// File     : /adm/daemons/network/dns_master.c

#include <ansi.h>
#include <mudlib.h>
#include <socket_err.h>
#include <net/config.h>
#include <net/daemons.h>
#include <net/dns.h>
#include <net/socket.h>
#include <net/services.h>
#include <net/macros.h>

#define STD_SERVICE ({ "mail", "finger", "rwho_q", "tell", "gwizmsg" })
#define MY_LOG_FILE "dns_master"

inherit F_DBASE;

protected int my_port = 8000, socket_id;
protected mapping muds, mud_svc, this_host, seq_entries, other_station = ([]);
protected mixed *bootsrv;
protected int bootsrv_retry;
protected int seq_ctr;

protected void read_callback(int sock, string msg, string addr);

protected void refresh_database();
protected void do_pings();
void set_mud_info(string name, mapping junk);
void zap_mud_info(string name);
void support_q_callback(mapping info);
protected void query_services(string mud, string address, string port, string tcp);

int query_service_method(string mud, string service);
string get_host_name(string alias);
int get_mudresource(string mud, string resource);
int dns_mudp(string name);

varargs int idx_request(function f);
protected void sequence_clean_up();

protected void aux_log(string file, string entry);
protected void log(string entry);
protected void resolve_callback(string address, string my_ip, int key);

int query_udp_port() {	return my_port; }
string query_mud_name() { return INTERMUD_MUD_NAME; }

string start_message()
{
	return sprintf( "||NAME:%s||VERSION:%s||MUDLIB:%s||HOST:%s||PORT:%d"
		"||PORTUDP:%d||TIME:%s||TCP:%s||USERS:%d",
		Mud_name(), MUDLIB_VERSION, MUDLIB_NAME, query_host_name(),
		mud_port(), my_port, ctime(time()), TCP_SERVICE_LEVEL, sizeof(users()));
}

mapping query_svc_entry(string mud)
{
	return copy(mud_svc[mud]);
}

protected int startup_udp()
{
	int err_no;

	if(socket_id)
		return 0;

	socket_id = socket_create(DATAGRAM, "read_callback", "close_callback");
	if (socket_id < 0) {
		log("Failed to acquire socket.\n");
		return 0;
	}

	err_no = socket_bind(socket_id, my_port);
	while( err_no == EEADDRINUSE )
	{
		my_port++;
		err_no = socket_bind(socket_id, my_port);
	}

	if( err_no <= 0 )
	{
		log( sprintf("Failed to bind socket of UDP services, error = %d.\n", err_no));
		socket_close(socket_id);
		return 0;
	}

	return 1;
}

void send_udp(string host, int port, string msg)
{
	int sock, n;
	string fname;
	object ob;

	if(objectp(ob = previous_object())
	&& (!ACCESS_CHECK(ob)
	|| (sizeof(fname = file_name(ob)) <= (n = sizeof(AUX_PATH)))
	|| (fname[0..n-1] != AUX_PATH)) )
		return;

	sock = socket_create(DATAGRAM, "read_callback", "close_callback");
	if(sock <= 0)
	{
		log("Failed to open socket to " + host + " " + port + "\n");
		return;
	}

	socket_write(sock, msg, sprintf("%s %d", host, port));
	socket_close(sock);
}

protected void read_callback(int sock, string msg, string addr)
{
	string func, rest, *bits, name, arg;
	mapping args;
	int i;

	if( !sscanf(msg, "@@@%s||%s@@@%*s", func, rest) )
	{
		if(!sscanf(msg, "@@@%s@@@%*s", func))
			return;
		rest = "";
	}

	sscanf(addr, "%s %*s", addr);

	if(undefinedp(other_station[addr]))
		return;

	bits = explode(rest, "||");
	args = allocate_mapping(i = sizeof(bits));
	while(i--)
		if (bits[i] && (sscanf(bits[i], "%s:%s", name, arg) == 2))
			args[name] = arg;
	args["HOSTADDRESS"] = addr;

	if(args["NAME"]) 
		args["ALIAS"] = htonn(args["NAME"]);

	if(mapp(muds[args["NAME"]]))
		muds[args["NAME"]][DNS_NO_CONTACT] = 0;

	if(file_size(AUX_PATH + func + ".c") > 0)
		(AUX_PATH + func)->incoming_request(args);
}

protected void send_shutdown()
{
	string *mud_names;
	int i;

	if(i = sizeof(mud_names = keys(muds)))
		while (i--)
			SHUTDOWN->send_shutdown(muds[mud_names[i]]["HOSTADDRESS"],
				muds[mud_names[i]]["PORTUDP"]);
	if(socket_id > 0)
		socket_close(socket_id);

	message("channel:sys", HIR"��ϵͳ���������飺�ͳ� shutdown ѶϢ��\n"NOR,
		filter_array(users(), (: wizardp($1) :)));
}

protected void init_database()
{
	int i;
	string message, *list;

	if( MUDLIST_A->query_db_flag() )
	{
		call_out("refresh_database", REFRESH_INTERVAL);
		call_out("sequence_clean_up", 4 * SERVICE_TIMEOUT);
		do_pings();
		message("channel:sys", HIR"��ϵͳ���������飺�ͳ� startup ѶϢ��\n"NOR,
			filter_array(users(), (: wizardp($1) :)));
		return;
	}

	message = sprintf("@@@%s%s@@@\n", DNS_STARTUP, start_message());

	if(i = sizeof(list = keys(other_station)))
	{
		while( i-- )
		{
			send_udp(list[i], other_station[list[i]], message);
			MUDLIST_Q->send_mudlist_q(list[i], other_station[list[i]]);
		}
	}
	call_out("init_database", 300);
}

protected void refresh_database()
{
	int i;
	string *list;

	remove_call_out("refresh_database");
	call_out("refresh_database", REFRESH_INTERVAL);

	if(i = sizeof(list = keys(other_station)))
	{
		while( i-- )
			MUDLIST_Q->send_mudlist_q(list[i], other_station[list[i]]);
	}
}

protected void do_pings()
{
	int i;
	string *mud_names;

	if(find_call_out("do_pings") != -1)
		return;

	call_out("do_pings", PING_INTERVAL);

	if( !i = sizeof(mud_names = keys(muds)) )
		return;

	while(i--)
	{
		if(undefinedp(mud_svc[mud_names[i]]))
			continue;

		muds[mud_names[i]][DNS_NO_CONTACT]++;

		PING_Q->send_ping_q(muds[mud_names[i]]["HOSTADDRESS"],
			muds[mud_names[i]]["PORTUDP"]);

		if(muds[mud_names[i]][DNS_NO_CONTACT] >= MAX_RETRYS)
			zap_mud_info(mud_names[i]);
	}
}

void set_mud_info(string name, mapping junk)
{
	int n;
	string fname, tcp;
	object ob;

	if(objectp(ob = previous_object())
	&& (!ACCESS_CHECK(ob)
	|| (sizeof(fname = file_name(ob)) <= (n = sizeof(AUX_PATH)))
	|| (fname[0..n-1] != AUX_PATH)) )
		return;
  
	name = htonn( name );
	while( name[strlen(name)-1] == '.' )
		name = name[ 0..strlen(name)-2 ];

	if(name == Mud_name())
		return;

	junk["ALIAS"] = nntoh( junk["NAME"] );

	if (!undefinedp(mud_svc[name]))
	{
		muds[name] = junk;
		return;
	}

	if(!undefinedp(muds[name]))
		aux_log("dns_mud_conv", "Udp contact from: "+name+"\n");

	if(!junk["TCP"])
		junk["TCP"] = TCP_NONE;

	muds[name] = junk;

	tcp = junk["TCP"];
	switch (tcp) {
	case TCP_ALL:
		mud_svc[name] = ([
			"mail"     :  SVC_TCP,
			"finger"   :  SVC_TCP | SVC_UDP | SVC_KNOWN,
			"tell"     :  SVC_TCP | SVC_UDP | SVC_KNOWN,
			"rwho_q"   :  SVC_UDP,
			"gwizmsg"  :  SVC_UDP,
		]);
		break;
	case TCP_ONLY:
		mud_svc[name] = ([
			"mail"     :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
			"finger"   :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
			"tell"     :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
			"rwho_q"   :  SVC_NO_UDP,
			"gwizmsg"  :  SVC_NO_UDP,
		]);
		break;
	case TCP_SOME:
		mud_svc[name] = ([
			"mail"     :  SVC_UNKNOWN,
			"finger"   :  SVC_UDP,
			"tell"     :  SVC_UDP,
			"rwho_q"   :  SVC_UDP,
			"gwizmsg"  :  SVC_UDP,
		]);
		break;
	default: // TCP_NONE
		mud_svc[name] = ([
			"mail"     :  SVC_NO_TCP,
			"finger"   :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
			"tell"     :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
			"rwho_q"   :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
			"gwizmsg"  :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
		]);
		break;
	} // switch (tcp)

	// handle service information
	if(tcp != TCP_ONLY)
		query_services(name, junk["HOSTADDRESS"], junk["PORTUDP"], tcp);
}

void zap_mud_info(string name)
{
	int n;
	string fname;
	object ob;

	if(objectp(ob = previous_object())
	&& (!ACCESS_CHECK(ob)
	|| (sizeof(fname = file_name(ob)) <= (n = sizeof(AUX_PATH)))
	|| (fname[0..n-1] != AUX_PATH)) )
		return;

	if(mapp(muds) && !undefinedp(muds[name]))
		map_delete(muds, name);

	if(mapp(mud_svc) && !undefinedp(mud_svc[name]))
		map_delete(mud_svc, name);
}

void support_q_callback(mapping info)
{
	string fname, cmd, mud;
	object ob;
	int n;

	if(objectp(ob = previous_object())
	&& (!ACCESS_CHECK(ob)
	|| (sizeof(fname = file_name(ob)) <= (n = sizeof(AUX_PATH)))
	|| (fname[0..n-1] != AUX_PATH)) )
		return;

	if(!mapp(info)
	|| !info["CMD"]
	|| !info["NAME"]
	|| !strlen(info["CMD"])
	|| !strlen(info["NAME"]) )
		return;

	mud = htonn( info["NAME"] );

	if(undefinedp(muds[mud]))
		return;

	if(undefinedp(mud_svc[mud]))
		mud_svc[mud] = ([]);

	if(!info["SUPPORTED"] && !info["NOTSUPPORTED"])
		return;

	if(info["CMD"] == "tcp")
	{
		cmd = info["PARAM"];

		if (mud_svc[mud][cmd] & (SVC_UDP | SVC_NO_UDP))
			mud_svc[mud][cmd] |= SVC_KNOWN;

		if (info["SUPPORTED"])
		{
			mud_svc[mud][cmd] |= SVC_TCP;
			mud_svc[mud][cmd] &= ~SVC_NO_TCP;
		}
		else
		{
			mud_svc[mud][cmd] |= SVC_NO_TCP;
			mud_svc[mud][cmd] &= ~SVC_TCP;

			if(!(mud_svc[mud][cmd] & SVC_KNOWN))
				SUPPORT_Q->send_support_q(muds[mud]["HOSTADDRESS"],
					muds[mud]["PORTUDP"], info["PARAM"]);
		}
	} // if (info["CMD"] == "tcp")

	else
	{
		cmd = info["CMD"];

		if(mud_svc[mud][cmd] & (SVC_TCP | SVC_NO_TCP))
			mud_svc[mud][cmd] |= SVC_KNOWN;

		if(info["SUPPORTED"])
		{
			mud_svc[mud][cmd] |= SVC_UDP;
			mud_svc[mud][cmd] &= ~SVC_NO_UDP;
		}
		else
		{
			mud_svc[mud][cmd] |= SVC_NO_UDP;
			mud_svc[mud][cmd] &= ~SVC_UDP;

			if(!(mud_svc[mud][cmd] & SVC_KNOWN))
				SUPPORT_Q->send_support_q(muds[mud]["HOSTADDRESS"],
					muds[mud]["PORTUDP"], "tcp", info["CMD"]);
		}
	} // if (info["CMD"] != "tcp")
}

protected void query_services(string mud, string address, string port, string tcp)
{
#ifdef PREF_MAIL
	if(!(mud_svc[mud]["mail"] & SVC_KNOWN))
	{
		if( (PREF_MAIL & SVC_TCP)
		&& (tcp == TCP_SOME)
		&& !(mud_svc[mud]["mail"] & (SVC_TCP | SVC_NO_TCP)))
			SUPPORT_Q->send_support_q(address, port, "tcp", "mail");

		else if((PREF_MAIL & SVC_UDP)
		&& !(mud_svc[mud]["mail"] & (SVC_UDP | SVC_NO_UDP)))
			SUPPORT_Q->send_support_q(address, port, "mail");
	}
#endif // PREF_MAIL

#ifdef PREF_FINGER
	if(!(mud_svc[mud]["finger"] & SVC_KNOWN))
	{
		if( (PREF_FINGER & SVC_TCP)
		&& (tcp == TCP_SOME)
		&& !(mud_svc[mud]["finger"] & (SVC_TCP | SVC_NO_TCP)))
			SUPPORT_Q->send_support_q(address, port, "tcp", "finger");
	}
#endif // PREF_FINGER

#ifdef PREF_TELL
	if(!(mud_svc[mud]["tell"] & SVC_KNOWN))
	{
		if( (PREF_TELL & SVC_TCP)
		&& (tcp == TCP_SOME)
		&& !(mud_svc[mud]["tell"] & (SVC_TCP | SVC_NO_TCP)))
			SUPPORT_Q->send_support_q(address, port, "tcp", "tell");
	}
#endif // PREF_TELL
}

int query_service_method(string mud, string service)
{
	if(!stringp(mud) || !sizeof(mud)
	|| !stringp(service) || !sizeof(service) )
		return SVC_UNKNOWN;

	mud = htonn(mud);

	if(undefinedp(muds[mud]))
		return SVC_UNKNOWN;

	if(undefinedp(mud_svc[mud]))
		return SVC_TCP | SVC_NO_UDP | SVC_KNOWN;

	if(undefinedp(mud_svc[mud][service]))
	{
		if(member_array(service, STD_SERVICE) != -1)
			query_services(mud, muds[mud]["HOSTADDRESS"], muds[mud]["PORTUDP"],
				muds[mud]["TCP"]);
		return SVC_UNKNOWN;
	}

	return mud_svc[mud][service];
}

string get_host_name(string name)
{
	if(!stringp(name) || !sizeof(name))
		return 0;

	name = htonn(name);

	if(name == mud_nname())
		return this_host["HOSTADDRESS"];

	if(undefinedp(muds[name]))
		return 0;

	return muds[name]["HOSTADDRESS"];
}

mapping query_mud_info(string name)
{
	if(!stringp(name) || !sizeof(name))
		return 0;

	name = htonn(name);
	if(name == mud_nname())
		return this_host + ([ "TIME" : ctime(time()) ])+
			(["USERS" : sprintf("%d",sizeof(users())) ]);
	return muds[name];
}

int dns_mudp(string name)
{
	if(!stringp(name) || !sizeof(name))
		return 0;

	name = htonn( name );
	return undefinedp(mud_svc[name]) ? (name == mud_nname() ? 1 : 0) : 1;
}

mapping query_muds()
{
	return muds + ([ mud_nname():this_host + ([ "TIME":ctime(time()) ])+
                ([ "USERS":sprintf("%d",sizeof(users())) ]) ]);
}

mapping query_svc()
{
	return copy(mud_svc);
}

varargs int idx_request(function f)
{
	int n;
	string fname;
	object ob;

	if(objectp(ob = previous_object())
	&& (!ACCESS_CHECK(ob)
	|| (sizeof(fname = file_name(ob)) <= (n = sizeof(AUX_PATH)))
	|| (fname[0..n-1] != AUX_PATH)) )
		return 0;

	seq_ctr++;
	seq_entries[seq_ctr] = ({ geteuid(previous_object()), f, time() });

	return seq_ctr;
}

void idx_callback(int idx, mixed param)
{
	mixed *entry;
	int n;
	string fname;
	object ob;

	if(objectp(ob = previous_object())
	&& (!ACCESS_CHECK(ob)
	|| (sizeof(fname = file_name(ob)) <= (n = sizeof(AUX_PATH)))
	|| (fname[0..n-1] != AUX_PATH)) )
		return;

	if(undefinedp(seq_entries[idx]))
		return;

	entry = seq_entries[idx];
	map_delete(seq_entries, idx);

	seteuid(entry[0]);
	(*entry[1])(param);
	seteuid(getuid());
}

protected void sequence_clean_up()
{
	int i, now;
	int *indexes;

	remove_call_out("sequence_clean_up");
	call_out("sequence_clean_up", SEQ_CLEAN_INTERVAL);

	if( i = sizeof(indexes = keys(seq_entries)) )
	{
		now = time();
		while(i--)
			if( now - seq_entries[indexes[i]][2] > SERVICE_TIMEOUT )
			{
				seteuid(seq_entries[indexes[i]][0]);
				(*seq_entries[indexes[i]][1])(0);
				seteuid(getuid());
				map_delete( seq_entries, indexes[i] );
			}
	}

	call_out("sequence_clean_up", SEQ_CLEAN_INTERVAL);
}

protected void aux_log(string file, string entry)
{
	log_file(file, sprintf("%s: %s\n", ctime(time()), entry));
}


protected void log(string entry)
{
	log_file(MY_LOG_FILE, sprintf("%s: %s\n", ctime(time()), entry));
}

protected void resolve_callback(string address, string my_ip, int key)
{
	this_host["HOSTADDRESS"] = my_ip;
}

protected void create()
{
	string *list;
	int i;

	seteuid(getuid());

	set("channel_id", "��·����");

	//my_port = SRVC_PORT_UDP(mud_port());

	muds = allocate_mapping(MUDS_ALLOC);
	mud_svc = allocate_mapping(MUDS_ALLOC);

	if(i = sizeof(list = values( LISTNODES )))
	{
		while(i--)
		{
			string address;
			int port;
			if(sscanf(list[i], "%s %d", address, port) == 2)
				other_station += ([ address : port ]);
		}
	}


	// initialise the sequencing variables
	seq_ctr = 0;
	seq_entries = ([]);

	// set the bootserver default
	bootsrv = MUDLIST_DNS;
	bootsrv_retry = 0;

	MUDLIST_A->clear_db_flag();

	this_host = ([
		"NAME"        : Mud_name(),
		"ALIAS"       : Mud_name(),
		"MUDLIB"      : MUDLIB_NAME,
		"VERSION"     : MUDLIB_VERSION,
		"HOST"        : query_host_name(),
		"HOSTADDRESS" : 0, // set in resolve_callback()
		"PORT"        : "" + mud_port(),
		"PORTUDP"     : "" + my_port,
		"TIME"        : ctime(time()),
		"TCP"         : TCP_SERVICE_LEVEL,
		"USERS"       : sprintf("%d",sizeof(users())),
	]);

	resolve(query_host_name(), "resolve_callback");

	// initialise the udp socket, if successful start the database system
	if(startup_udp())
		init_database();
}

void remove()
{
	if( !previous_object()
	|| (previous_object() != find_object(SIMUL_EFUN_OB)) )
		return;

	send_shutdown();
}
