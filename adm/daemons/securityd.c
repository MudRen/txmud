// securityd.c
// Modified by Find.

#include <login.h>

// By Annihilator@Eastern.Stories (11/25/94)

// This is the "effective" access status compare to the "status" property
// in login object that this mapping determine wizards' access rights
// directly. It is important to make the "status" property matches this
// mapping for wizards higher than regular wizard such as sage, arch and
// admin. For thoese users whose name doesnot appear in this mapping, they
// are divided into three groups (wizard),(player) and (object) using
// wizardp() and interactive() efun.
// The parenthesis is nessessary to prevend players naming themself "admin"
// to hack the security system.
// 
// 01/14/95 Annihilator - wiz_status are defined outside this daemon in the
//                        WIZLIST file.

protected mapping wiz_status;

protected string *wiz_levels = ({
        "(player)",
        "(adviser)",
        "(apprentice)",
        "(wizard)",
        "(sage)",
        "(arch)",
        "(admin)"
});

// A valid write attempt must pass 2 checks: your uid or status must not be
// "excluded" and must be "trusted" on that directory in order to write in 
// that directory. The directories containing the file is searched backward
// from the current directory to root. And exclude is checked prior than
// trusted.

protected mapping trusted_write = ([
        "/":                    ({ "(admin)" }),
        "open":                 ({ "(wizard)", "(apprentice)", "(sage)", "(arch)" }),
	"include":              ({ "(arch)" }),
	"obj":                  ({ "(arch)" }),
	"daemon":               ({ "(arch)" }),
	"quest":                ({ "(arch)" }),
	"wiz":                  ({ "(arch)" }),
]);

protected mapping exclude_write = ([
        "adm":          ({ "(arch)" }),
        "std":          ({ "(arch)" }),
        "cmds":         ({ "(arch)" }),
        "log":          ({ "(arch)" }),
	"obj/user":	({ "(arch)", "(sage)", "(wizard)", "(apprentice)", "(adviser)" }),
	"data":		({ "(arch)", "(sage)", "(wizard)", "(apprentice)", "(adviser)" }),
]);

protected void write_log(string euid,string status,string func,string file);

protected void create()
{
        string *wizlist, wiz_name, wiz_level;
        int i;

	seteuid(getuid());

	if(file_size(WIZLIST) <0)
	{
		wiz_status = ([]);
		return;
	}

        wizlist = explode(read_file(WIZLIST), "\n");
        wiz_status = allocate_mapping(sizeof(wizlist));
        for(i=0; i<sizeof(wizlist); i++)
	{
                if( wizlist[i][0]=='#' 
                || sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
                wiz_status[wiz_name] = wiz_level;
        }
}

string *query_wizlist() { return keys(wiz_status); }

// This function returns the status of an uid.
string get_status(mixed ob)
{
        string euid;
        
        if( objectp(ob) ) {
                euid = geteuid(ob);
                if( !euid ) euid = getuid(ob);
        }
        else if( stringp(ob) ) euid = ob;

        if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
        else if( member_array(euid, wiz_levels)!=-1 ) return euid;
        else return "(player)";
}

string query_wizlevel_name(int i)
{
	string name;

	if( !intp(i) || i<0 || i>=sizeof(wiz_levels) )
		return "Error: No this level.!";
	else
	{
		sscanf(wiz_levels[i],"(%s)",name);
		return capitalize(name);
	}
}

int get_wiz_level(mixed ob)
{
        return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, string status)
{
        string uid, *wiz, wizlist;
        int i;
        string old_status;
	object p_cmd;

	if( objectp(p_cmd = find_object("/cmds/arch/promote"))
	&& !clonep(p_cmd) )
	{
		if( previous_object(0) != p_cmd )
			return 0;
	}
        else return 0;

	if(objectp(ob) && userp(ob)) uid = getuid(ob);
        else if(stringp(ob)) uid = ob;
        else return 0;

        old_status = get_status(uid);
        
        if( status == "(player)" )
                map_delete(wiz_status, uid);
        else
                wiz_status[uid] = status;
        wiz = keys(wiz_status);
        for(wizlist = "", i=0; i<sizeof(wiz); i++)
                wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
        write_file(WIZLIST, wizlist,1);

        sys_log( "promotion", sprintf("%s%s promote %s from %s to %s on %s\n",
                capitalize(geteuid(this_player(1))),get_status(this_player(1)),capitalize(uid),
                old_status,status,ctime(time()) ) );

        return 1;
}

string *get_wizlist() { return keys(wiz_status); }

// valid_write - called by the master object to determine whether if an user
//               is allowed to write on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object.             - Annihilator

int valid_write(string file, mixed user, string func)
{
        string euid, status, *path, dir;
        int i;
        string name,domain;

        if( !objectp(user) )
                error("SECURITY_D->valid_write: Invalid argument type of user.\n");

	if( (file == WIZLIST)
	&& (user != this_object()) )
		return 0;

        if(file == "/adm/daemons/securityd.c"
	|| file == "/cmds/arch/promote.c"
	|| file == "/adm/obj/master.c"
	|| file == "/include/globals.h" )
		return 0;

	euid = geteuid(user);

        if( (sscanf(file, LOG_DIR + "%*s")
	|| sscanf(file, "/syslog/%*s"))
	&& func=="write_file"
	&& user == find_object(SIMUL_EFUN_OB))
		return 1;

	if(sscanf(file, "/syslog/%*s")
	&& ((func != "write_file")
	|| (user != find_object(SIMUL_EFUN_OB))))
		return 0;

	/* ��ͬĿ¼�� save_object��write_file ��� . Find */
	if( (sscanf(file, "/d/%*s")
	|| sscanf(file, sprintf("/%s/%%*s",BANGHUI_DIR)) )
	&& in_same_dir(file,base_name(user))
	&& (func == "save_object" || func == "write_file"))
		return 1;

        // Let user save their save file
        if( func=="save_object" )
	{
		if( sscanf(file, "/obj/login/%*s")
		|| sscanf(file, "/obj/user/%*s") )
		{
			string id;

			if(sscanf(file,sprintf("/obj/login/%c/%%s.o",euid[0]),id)
			&& (id == euid) )
				return 1;
			if(sscanf(file,sprintf("/obj/user/%c/%%s.o",euid[0]),id)
			&& (id == euid) )
				return 1;
		}

		else
		{
			if( (sscanf(base_name(user), "/obj/%*s")
	                && sscanf(file, "/data/%*s") )
	                || ( sscanf(base_name(user), "/d/phome/%*s")
	                && sscanf(file, "/d/phome/%*s"))
			|| sscanf(file, "/data/hockshop/%*s") )
	                        return 1;
	
			if(sscanf(file, "/data/business/%*s"))
			{
				if(!sscanf(file_name(user),"/d/%s/business",domain))
					return 0;
				if(member_array(domain,BUSINESS_D->query_valid_domains()) == -1)
					return 0;
				return 1;
			}
		}
        }

        // Get the euid and status of the user.
	if( !euid )
		return 0;
	status = get_status(user);

        if( euid==ROOT_UID ) return 1;

        if( sscanf(file, WIZ_DIR + euid + "/%*s") && wiz_level(euid))
                return 1;
        if( sscanf(file, WIZ_DIR+"%s/%*s",name) )
        {
                if( (name != euid) && (status != "(admin)") )
                        return 0;
        }

        path = explode(file, "/");

        // Check if we are excluded in one of the directories containing the file.
        for(i=sizeof(path)-1; i>=0; i--)
	{
                dir = implode(path[0..i], "/");
                if( undefinedp(exclude_write[dir]) ) continue;
                if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
                if( member_array(status, exclude_write[dir])!=-1 ) return 0;
        }

        // And then check if we are trusted in one of the directories containing
        // the file.

        if( member_array(euid, trusted_write["/"])!=-1 )
	{
		call_out("write_log",1,euid,status,func,file );
		return 1;
	}
	if( member_array(status, trusted_write["/"])!=-1 )
	{
		call_out("write_log",1,euid,status,func,file );
		return 1;
	}
	for(i=sizeof(path)-1; i>=0; i--)
	{
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_write[dir]) ) continue;
		if( member_array(euid, trusted_write[dir])!=-1 )
		{
			call_out("write_log",1,euid,status,func,file );
			return 1;
		}
		if( member_array(status, trusted_write[dir])!=-1 )
		{
			call_out("write_log",1,euid,status,func,file );
			return 1;
		}
	}
	return 0;
}

protected void write_log(string euid,string status,string func,string file)
{
        if(func == "read_file") return;
        sys_log("write",sprintf("%s%s %s (%s) in (%s)\n",
        euid,status,func,file,ctime(time())));
        return;
}

int valid_seteuid( object ob, string uid )
{
        if( uid==0 ) return 1;
        if( uid==getuid(ob) ) return 1;
        if( getuid(ob)==ROOT_UID ) return 1;
        if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
        if( wiz_status[uid] != "(admin)"
        && wiz_status[getuid(ob)] == "(admin)" )
                return 1;
        return 0;
}
