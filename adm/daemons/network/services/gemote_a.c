// gemote_a.c
// for intermud emote

// by By Find (11/25/98)

#undef DEBUG

#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/services.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

void create() { seteuid(ROOT_UID); }

void incoming_request(mapping info)
{
	string str,msg,*names;
	mapping minfo,muds,svcs;
	int i;

	if(!ACCESS_CHECK(previous_object()))
		return;

	if (!info["NAME"] || !info["TONAME"] || !info["PORTUDP"])
		return;

	if (info["NAME"] == Mud_name())
		return ;

	minfo = DNS_MASTER->query_mud_info(info["NAME"]);
	if(!minfo || !DNS_MASTER->dns_mudp(info["NAME"]))
		PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

	if (minfo && minfo["HOSTADDRESS"] != info["HOSTADDRESS"])
	{
		// Its been faked! 
		dns_log("dns_fake", "Emotefrom: "+info["EMOTEFROM"]+"@"+info["NAME"]+
			"("+info["HOSTADDRESS"]+") Emoteto "+info["EMOTETO"]
			+" "+ info["MSG"]+"\n");
		DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
			"@@@"+DNS_WARNING+
			"||MSG: Faked gemote message "+info["WIZFROM"]+
			"@"+info["NAME"]+"> "+info["EMOTETO"]+
			" "+info["MSG"]+
			"||FAKEHOST:"+info["HOSTADDRESS"]+
			"@@@\n");
		return ;
	}

#ifdef DEBUG
	set("channel_id", "���� EMOTE ���վ���");
	CHANNEL_D->do_channel(this_object(), "sys",
		sprintf("Receive a emote request from (%s),EMOTEFROM (%s) EMOTETO (%s) CHANNEL (%s).",
		info["NAME"],info["EMOTEFROM"],info["EMOTETO"],info["CHANNEL"]));
#endif


	msg = info["MSG"];

	msg = replace_string(msg,"$n",sprintf("%s(%s@%s)",
		info["TONAME"], info["EMOTETO"], info["NAME"]));

        str = replace_string(msg,"$N",(string)info["CNAME"]);

	set("channel_id", "���ʶ�������");
	CHANNEL_D->do_channel(this_object(), lower_case(info["CHANNEL"]),str,1);

	muds = (mapping)DNS_MASTER->query_muds();
	svcs = (mapping)DNS_MASTER->query_svc();

	names = keys(svcs);
	i = sizeof(names);

	while(i--)
		if( names[i] != mud_nname() && names[i]!= info["NAME"])
		{
			minfo = muds[names[i]];
			if(!mapp(minfo) || !mapp(svcs[names[i]])
			|| !(svcs[names[i]]["gwizmsg"] & SVC_UDP))
				continue;
			msg = replace_string(msg,"$N",sprintf("%s(%s@%s)",
			info["CNAME"], info["EMOTEFROM"], mud_nname()));

			DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
				"@@@" + DNS_GCHANNEL +
				"||NAME:" + Mud_name() +
				"||PORTUDP:" + udp_port() +
				"||USRNAME:" + info["EMOTEFROM"] +
				"||CNAME:" + info["CNAME"] +
				"||MSG:" + msg +
				"||CHANNEL:" + info["CHANNEL"] +
				"||EMOTE:1" + "@@@\n");
		}
}
