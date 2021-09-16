// master.c
// Modified by Find.

protected
mapping trusted_read = ([
	"/":                    ({ "(admin)" }),
	"open":                 ({ "(arch)", "(sage)", "(wizard)", "(apprentice)", "(adviser)" }),
	"include":              ({ "(arch)", "(sage)", "(wizard)" }),
	"obj":			({ "(arch)" }),
	"quest":		({ "(arch)", "(sage)", "(wizard)" }),
	"data":                 ({ "(arch)" }),
	"log":			({ "(arch)", "(sage)", "(wizard)", "(apprentice)", "(adviser)" }),
	"syslog":               ({ "(arch)" }),
	"doc":                  ({ "(arch)", "(sage)", "(wizard)", "(apprentice)", "(adviser)" }),
	"wiz":                  ({ "(arch)", "(sage)", "(wizard)", "(apprentice)" }),
	"d/changan":		({ "(arch)", "(sage)", "(wizard)", "(apprentice)" }),
	"doc/help":		({ "zling" }),
	"d/huashan":		({ "aiai"}),
	"d/huashan_zx":		({ "aiai"}),
	"d/path2":		({ "aiai"}),
        "d/jinghai":            ({ "zling" }),
	"d/gaibang":		({ "tag"}),
	"daemon/skill/gaibang": ({ "tag"}),
	"daemon/class/gaibang": ({ "tag"}),
        "d/tangmen":            ({ "qifan" }),
        "daemon/skills/tangmen":            ({ "qifan" }),
        "daemon/class/tangmen":             ({ "qifan" }),
        "quest/tangmen":        ({ "qifan" }),
]);

protected
mapping exclude_read = ([
	"data/mail":		({ "(arch)" }),
	"data/login":		({ "(arch)" }),
	"obj/user":		({ "(sage)", "(wizard)" }),
]);

protected
mapping no_hide = ([
//	"syslog":	({ "(admin)", "(arch)" }),
]);

object connect()
{
	object login_ob;
	mixed err;

	err = catch(login_ob = new(LOGIN_OB));

	if (err) {
		write("�������������޸�ʹ�������߲��ݵĳ�ʽ�������������\n");
		write(err);
		destruct(this_object());
	}
	return login_ob;
}

mixed compile_object(string file)
{
	object daemon;

	if( daemon = find_object(VIRTUAL_D) )
		return daemon->compile_object(file);
	else
		return 0;
}

protected void crash(string error, object command_giver, object current_object)
{
	efun::shout("ϵͳ���ķ���һ���ҽУ��ۡ������֡�\n");
	efun::shout("ϵͳ���ĸ����㣺Ҫ�����ˣ��Լ����ذɣ�\n");

	// ��ĳЩ����������п������������ҵ������ҡ��ٻ�
	// ��û�б��ݻ��Ƶ�ϵͳ����ò�Ҫ�á�
	// by Find.
	users()->save();
	efun::shout("�����̾��顿�����ĵ����Ѿ����������ˡ�");
	// end.

	log_file("static/crashes", MUD_NAME + " crashed on: " + ctime(time()) +
		", error: " + error + "\n");
	if (command_giver)
		log_file("static/crashes",
			sprintf( "this_player: %O\n", command_giver));
	if (current_object)
		log_file("static/crashes",
			sprintf( "this_object: %O\n", current_object));
}

string *epilog(int load_empty)
{
	string *items;

	items =  filter_array(explode(read_file(CONFIG_DIR + "preload"), "\n") - ({ "" }), (: $1[0] != '#' :));

#ifndef GB_AND_BIG5
	if(!load_empty)
        if(member_array("/adm/daemons/convertd",items) != -1 )
                items -= ({"/adm/daemons/convertd"});
#endif
	return items;
}

protected void preload(string file)
{
	int t1;
	string err;

	if (file_size(file + ".c") == -1)
		return;

	t1 = time();
	efun::write_file("/log/debug.log",sprintf("Preloading : %-40s", file) );
	err = catch(call_other(file, "??"));
	if (err)
		efun::write_file("/log/debug.log"," -> Error " + err + " when loading " + file + "\n");
	else
		efun::write_file("/log/debug.log",".... Done.\n");
		
}

void log_error(string file, string message)
{
	string name, home;
   
	if( find_object(SIMUL_EFUN_OB) )
		name = file_owner(file);

	if (name) home = user_path(name);
	else home = LOG_DIR;

	if(this_player(1)) efun::write("����ʱ�δ���" + message+"\n");
	
	efun::write_file(home + "log", message);
}

int save_ed_setup(object who, int code)
{
	string file;
  
	if (!intp(code))
		return 0;
	file = user_path(getuid(who)) + ".edrc";
	rm(file);
	return write_file(file, code + "");
}

int retrieve_ed_setup(object who)
{
	string file;
	int code;

	file = user_path(getuid(who)) + ".edrc";
	if (file_size(file) <= 0)
		return 0;

	sscanf(read_file(file), "%d", code);
	return code;
}

void destruct_env_of(object ob)
{
	if (!interactive(ob))
		return;
	tell_object(ob, "�������ڵĿռ䱻�����ˡ�\n");
	ob->move(VOID_OB);
}

string make_path_absolute(string file)
{
	file = resolve_path((string)this_player()->query("cwd"), file);
	return file;
}

string get_save_file_name(string fname)
{
	return sprintf("%s.%d", fname , time());
}

string get_root_uid()
{
	return ROOT_UID;
}

string get_bb_uid()
{
	return BACKBONE_UID;
}

string creator_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "creator_file", str);
}

string domain_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "domain_file", str);
}

string author_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "author_file", str);
}

string standard_trace(mapping error, int caught)
{
    int i, s;
    string res;

    /* keep track of number of errors per object...if you're into that */

    res = (caught) ? "����ѶϢ������: " : "";
    res = sprintf("%s\nִ��ʱ�δ���%s\n��ʽ��%s �� %i ��\n���: %s\n",
    	res, error["error"],
        error["program"], error["line"],
        file_name(error["object"]));

    for (i=0, s = sizeof(error["trace"]); i < s; i++) {
		res = sprintf("%s�������ԣ�%s �� %s() �� %i �У������ %O\n",
			res,
			error["trace"][i]["program"],
            error["trace"][i]["function"],
            error["trace"][i]["line"],
            error["trace"][i]["object"] );
    }
    return res;
}

string error_handler( mapping error, int caught )
{
	if(this_player(1))
	{
		this_player(1)->set_temp("error", error);
		tell_object(this_player(1), standard_trace(error, caught));
	}

	return standard_trace(error, caught);
}

int valid_shadow( object ob, object shadow_ob )
{
	return 0;
}

int valid_override( string file, string name )
{
	string *overrides;
	if (file == SIMUL_EFUN_OB || file==MASTER_OB)
		return 1;

	if(((name == "move_object") || (name == "destruct")) && (file != F_MOVE))
		return 0;

	// added by find.
	// To avoid some crashers or some security holes.
	overrides = ({"shutdown","localtime","ctime","exec","snoop"});
        if( member_array(name,overrides) != -1 )
                return 0;
	// end.

	return 1;
}

int valid_seteuid( object ob, string str )
{
	return (int)SECURITY_D->valid_seteuid( ob, str );
}

int valid_socket( object eff_user, string fun, mixed *info )
{
	if(!eff_user || !objectp(eff_user))
		return 0;
	if(geteuid(eff_user) != ROOT_UID)
		return 0;
	return 1;
}

int valid_asm( string file )
{
	return 1;
}

int valid_compile_to_c( string file )
{
	return 1;
}

int valid_hide( object who )
{
	return 1;
}

int valid_object( object ob )
{
	return (!clonep(ob)) || inherits(F_MOVE, ob);
}

int valid_link( string original, string reference )
{
	return 0;
}

int valid_save_binary( string filename )
{
	return 1;
}

int valid_write( string file, mixed user, string func )
{
	object ob;

	if(objectp(user)
	&& (user == this_object())
	&& sscanf(file, LOG_DIR + "%*s"))
		return 1;
	if( ob = find_object(SECURITY_D) )
		return (int)SECURITY_D->valid_write(file, user, func);

	return 0;
}

int valid_read( string file, mixed user, string func )
{
        string euid, status, *path, dir;
        int i;

	if( sscanf(file, "/syslog/%*s") )
        {
                if(this_player(1)
                && wiz_level(this_player(1)) < wiz_level("(arch)"))
                        return 0;
        }

        if( sscanf(file,"/data/mail/%*s")
        && (base_name(user) != MAILBOX_OB)
        && (func == "restore_object"))
                return 0;

	if( (func == "restore_object") || in_same_dir(file,base_name(user)) )
		return 1;

	euid = geteuid(user);
	if(!euid)
		return 1;
	if(euid == ROOT_UID)
		return 1;
	status = wizhood(euid);

        if( sscanf(file, "/wiz/" + euid + "/%*s") )
                return 1;

        path = explode(file, "/");

	if(func == "file_size" || func == "stat")
	{
		if(!no_hide || !sizeof(no_hide) )
			return 1;
		for(i=sizeof(path)-1; i>=0; i--)
		{
			dir = implode(path[0..i], "/");
			if( undefinedp(no_hide[dir]) ) continue;
			if( member_array(euid, no_hide[dir])!=-1 )
				return 1;
			if( member_array(status, no_hide[dir])!=-1 )
				return 1;
			return 0;
		}
		return 1;
	}

        for(i=sizeof(path)-1; i>=0; i--)
	{
                dir = implode(path[0..i], "/");
                if( undefinedp(exclude_read[dir]) ) continue;
                if( member_array(euid, exclude_read[dir])!=-1 ) return 0;
                if( member_array(status, exclude_read[dir])!=-1 ) return 0;
        }

        if( member_array(euid, trusted_read["/"])!=-1 )
		return 1;
        if( member_array(status, trusted_read["/"])!=-1 )
		return 1;
        for(i=sizeof(path)-1; i>=0; i--)
	{
                dir = implode(path[0..i], "/");
                if( undefinedp(trusted_read[dir]) ) continue;
                if( member_array(euid, trusted_read[dir])!=-1 )
                        return 1;
                if( member_array(status, trusted_read[dir])!=-1 )
                        return 1;
        }

	return 0;
}

string object_name(object ob)
{
	if( ob ) return ob->name();
}

protected void create()
{
	if(clonep())
		return;
	write("master: loaded successfully.\n");
	//call_out("free_objects", 3600);
}

// Added by Find for cycle reclaim no-use memory
protected void free_objects()
{
	remove_call_out("free_objects");
	efun::reclaim_objects();
	call_out("free_objects", 3600);
}

int valid_bind(object binder, object old_owner, object new_owner)
{
	if( userp(new_owner) ) return 0;
	if( geteuid(binder)==ROOT_UID ) return 1;
	if( clonep(new_owner) ) return 1;
	return 0;
}

// Added by Find.
mixed valid_database(object ob, string action, mixed *info)
/*
 * Return: string - password for access
 *         int    - 1 for no password, accept, 0 deny
 */
{
	if(!objectp(ob) || (geteuid(ob) != ROOT_UID))
		return 0;

	else
	{
		if(action == "connect")
			switch (info[1])
			{
				case "localhost":
					return "123";
				default:
					return 0;
			}

		else
			return 1;
	}
}

int view_errors( object user )
{
	if(!user)
		return 0;
	if(wizardp(user))
		return 1;
	else return 0;
}

void flag(string arg)
{
	if(!arg || arg == "")
		return;
	log_file("flag",arg+"\n");
}
