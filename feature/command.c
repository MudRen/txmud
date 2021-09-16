// command.c
// Modified by Find.

#pragma optimize

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <block_cmds.h>

static string *path;
static string *ghost_path = ({"/cmds/ghost/"});

private nomask int check_invalid_esc(string arg);
private nomask int check_invalid_ee(string arg);
private nomask int check_chat_point(string arg);

string find_command(string verb)
{
        return (string)COMMAND_D->find_command(verb,
	( (this_object()->is_ghost()
	&& !wizardp(this_object()))
	|| ((query("id") == "guest")
	&& userp(this_object()) ) )?ghost_path:path); /* by Find. */
}

varargs string remove_leading_space(string arg,int flag)
{
        int i,n;

	if(!stringp(arg) || arg =="")
		return flag?arg:"";

	n = strlen(arg);

	for (i = 0; i<n; i++)
                if (arg[i] != ' ')
                        return arg[i..<1];
        return flag?arg:"";
}

private nomask int command_hook(string arg)
{
        string verb, file;
	string *fuji_verb,*cht_vbs = ({"chat","menpai","rumor","tx"});

#ifdef PROFILE_COMMANDS
        int mem, utime, stime;
        mapping info;

        mem = memory_info();
        info = rusage();
        utime = info["utime"];
        stime = info["stime"];
#endif

        verb = query_verb();

	// completely remove leading space. Find.
        if(verb == "")
	{
		arg = remove_leading_space(arg);
		if(arg == "")
			return 1;
		if(sscanf(arg,"%s %s",verb,arg) != 2)
		{
			verb = arg;
			arg = 0;
		}
	}

	fuji_verb = ({"tell","say","l","look","i","score","hp","enable","enforce","unfuji","skills"});
	if(query_temp("fuji_player")
	&& member_array(verb,fuji_verb) == -1)
		return notify_fail("�����ڲ���������ˣ��������±�¶��\n");

	if( (member_array(verb,cht_vbs) != -1) && arg )
	{
		if(this_object()->query("channel/chat_block")
		&& (time() - this_object()->query("channel/chat_block")) < 0 )
			return notify_fail("��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");

		if( sscanf(arg,"%*s[%*s") && !check_invalid_esc(arg))
			return 0;
		if( sscanf(arg,"%*s%%e[%*s") && !check_invalid_ee(arg))
			return 0;
		if(!check_chat_point(arg))
			return 0;
	}

	if(environment() && environment()->query(SAFE_ENV))
		if(member_array(verb,BLOCK_CMDS) != -1)
			return notify_fail("��ȫ������ʹ��������\n");
	if( !arg
	&& (environment() && stringp(environment()->query("exits/" + verb)))
	&& stringp(file = find_command("go"))
	&& call_other(file, "main", this_object(), verb))
		;

	else if( stringp(file = find_command(verb)) 
	&& call_other(file, "main", this_object(), remove_leading_space(arg,1)))
		;

	else if(query("id") == "guest")
		return 0;

	else if( EMOTE_D->do_emote( this_object(), verb, arg ) )
		;

	else if( CHANNEL_D->do_channel( this_object(), verb, arg ) )
		;

	else return 0;

#ifdef PROFILE_COMMANDS
	info = rusage();
	PROFILE_D->log_command(verb, memory_info() - mem, info["stime"] - stime,
		info["utime"] - utime);
#endif

	return 1;
}

private nomask void set_path(string *p)
{
        string cs;

        if( stringp(cs = this_object()->query("class"))
        && (member_array(sprintf("/d/%s/cmds/",cs),p) == -1) )
                p += ({ sprintf("/d/%s/cmds/",cs) });
	if(wizardp(this_object()))
		p += ({ "/cmds/bangzhu/" });
        path = p;
}

string *query_path() { return path; }
mixed *query_commands() { return commands(); }

int force_me(string cmd)
{
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;

        return command( this_object()->process_input(cmd) );
}

nomask void enable_player()
{
        if( stringp(query("id")) )
		set_living_name(query("id"));
        else set_living_name(query("name"));

        enable_commands();
        add_action("command_hook", "", 1);

        if( !userp(this_object()) )
                set_path(NPC_PATH);
        else
        switch( wizhood(this_object()) )
	{
                case "(admin)":
			enable_wizard();
                        set_path(ADM_PATH);
                        break;
                case "(sage)":
			enable_wizard();
                        set_path(SAG_PATH);
                        break;
                case "(arch)":
			enable_wizard();
                        set_path(ARC_PATH);
                        break;
                case "(wizard)":
			enable_wizard();
                        set_path(WIZ_PATH);
                        break;
                case "(apprentice)":
			enable_wizard();
                        set_path(APR_PATH);
                        break;
                case "(adviser)":
                        set_path(IMM_PATH);
                        break;
                default:
                        set_path(PLR_PATH);
        }
}

nomask void disable_player(string type)
{
        if( geteuid(previous_object())!=ROOT_UID
        && previous_object()!=this_object())
		return;

        set("disable_type", type);
        disable_commands();
}

private nomask int check_invalid_esc(string arg)
{
	int x,y;

	if(!stringp(arg) || (arg == "") )
		return 1;

	if(sscanf(arg,"%*s[2J%*s") == 2)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[H%*s") == 2)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[2J%*s") == 2)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[s%*s") == 2)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[u%*s") == 2)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[K%*s") == 2)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[%dA%*s",x) == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[%dB%*s",x) == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[%dC%*s",x) == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[%dD%*s",x) == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[%d;%dH%*s",y,x) == 4)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[M%*s") == 2)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[%dM%*s",x) == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[%d@%*s",x) == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[%dP%*s",x) == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s[%dh%*s",x) == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	return 1;
}

private nomask int check_invalid_ee(string arg)
{
	int x,y;

	if(!stringp(arg) || (arg == ""))
		return 1;

	if(sscanf(arg,"%*s%%e[2J%*s") == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[H%*s") == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[2J%*s") == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[s%*s") == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[u%*s") == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[K%*s") == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[%dA%*s",x) == 4)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[%dB%*s",x) == 4)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[%dC%*s",x) == 4)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[%dD%*s",x) == 4)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[%d;%dH%*s",y,x) == 5)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[M%*s") == 3)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[%dM%*s",x) == 4)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[%d@%*s",x) == 4)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[%dP%*s",x) == 4)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s%%e[%dh%*s",x) == 4)
	{
		this_object()->set("channel/chat_block",time()+30*60);
		return notify_fail("��������ͼ������Ϸ���������У���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	return 1;
}

private nomask int check_chat_point(string arg)
{
	if(!stringp(arg) || (arg == ""))
		return 1;

	if(sscanf(arg,"%*s\n��������桿%*s"))
	{
		this_object()->set("channel/chat_block",time()+180);
		return notify_fail("��������ͼ���͵�Ƶ����Ϣ�и�����Ϸ���еĿ����ԣ���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s\n���������ߡ�%*s"))
	{
		this_object()->set("channel/chat_block",time()+180);
		return notify_fail("��������ͼ���͵�Ƶ����Ϣ�и�����Ϸ���еĿ����ԣ���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s\n�������ˬ��%*s"))
	{
		this_object()->set("channel/chat_block",time()+180);
		return notify_fail("��������ͼ���͵�Ƶ����Ϣ�и�����Ϸ���еĿ����ԣ���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	if(sscanf(arg,"%*s\n����ѩ������%*s"))
	{
		this_object()->set("channel/chat_block",time()+180);
		return notify_fail("��������ͼ���͵�Ƶ����Ϣ�и�����Ϸ���еĿ����ԣ���Ľ�̸Ƶ�����ر��ˡ�\n");
	}
	return 1;
}
