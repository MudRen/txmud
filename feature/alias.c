// alias.c
// Modified by Find.

#pragma optimize

#define MAX_REPEAT 30
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10

mapping alias;

static string *history, last_input;
static int last_cmd, repeat_cnt = 0, robot_check = uptime();
static string * no_busy_cmds = ({ "hp","score","inventory","look","l","skills","boss","id","save","time","uptime","wizlist","version",});

private string control_acction_from_wizardob(string cmd);

string remove_leadspace(string arg)
{
        int i;

	if(!stringp(arg) || arg =="")
		return "";
        for (i = 0; i < strlen(arg); i++)
                if (arg[i..i] != " ")
                        return arg[i..strlen(arg)];
        return "";
}

nomask string process_input(string str)
{
	string *args, cmd, argstr,temp;
	int i, j;
	object me=this_object();

	if(!living(me))
		return "";

	if(me->query_temp("entering_world"))
		return "";

	if(me->is_busy() && (member_array(str,no_busy_cmds) == -1))
	{
		tell_object(this_object(),BUSY_MESSAGE);
		return "";
	}

	if( uptime() < (robot_check + 3))
	{
		repeat_cnt++;
		if((repeat_cnt > MAX_REPEAT)&& !wizardp(me) )
		{
			message_vision("$NͻȻһ��ͷ��Ŀѣ��ɵɵ��վ���ⲻ���ˡ�\n", me);
			me->start_busy(6);
			repeat_cnt = 0;
			robot_check = uptime();
		}
	}

	else
	{
		robot_check = uptime();
		repeat_cnt = 0;
	}

	str = remove_leadspace(str);
	str = replace_string(str, "", " ");

	if( str[0]=='!' )
	{
		if( pointerp(history) && sizeof(history) )
		{
			if( sscanf(str, "!%d", i) )
				str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
			else
				str = history[last_cmd];
		}

		else
			return "";
	}

	else
	{
		if( !pointerp(history) )
			history = allocate(HISTORY_BUFFER_SIZE);
		last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
		history[last_cmd] = str;
	}

	if( mapp(alias) )
	{
		if( !undefinedp(alias[str]) )
		{
			temp = replace_string( alias[str], "$*", "" );
#ifdef WIZARD_FLAG
			temp = control_acction_from_wizardob(temp);
#endif
			return temp;
		}

		if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) )
		{
			cmd = replace_string( alias[cmd], "$*", argstr );
			args = explode(argstr, " ");
			if( (j = sizeof(args)) )
				for(i=0; i<j; i++)
					cmd = replace_string( cmd, "$" + (i+1), args[i] );
#ifdef WIZARD_FLAG
			cmd = control_acction_from_wizardob(cmd);
#endif
			return cmd;
		}
	}

	temp = (string)ALIAS_D->process_global_alias(str);
#ifdef WIZARD_FLAG
	temp = control_acction_from_wizardob(temp);
#endif
	return temp;
}

nomask int set_alias(string verb, string replace)
{
	if( !replace )
	{
		if( mapp(alias) ) map_delete(alias, verb);
			return 1;
	}

	else
	{
		if( !mapp(alias) )
			alias = ([ verb:replace ]);
		else if( sizeof(alias) > MAX_ALIASES )
			return notify_fail("���趨�� alias ̫���ˣ�����ɾ��һЩ�����õġ�\n");
		else alias[verb] = replace;
		return 1;
	}
}

mapping query_all_alias()
{
	return alias;
}

/* Players can not use the actions from wiz_ob. by Find.*/
private string control_acction_from_wizardob(string cmd)
{
	mixed *cmds;
	int i;
	string str;

	if(!stringp(cmd) || cmd == "")
		return "";

	sscanf(cmd,"%s %*s",str);
	if(str == "")
		return str;

	if(!str)
		str = cmd;
	cmds = this_object()->query_commands();
	for(i=0;i<sizeof(cmds);i++)
	{
		if( (cmds[i][0] == str)
		&& !wizardp(this_object()))
		{
			if( sscanf(file_name(cmds[i][2]),WIZ_DIR+"%*s")
			|| cmds[i][2]->query_wiz_flag())
				return "";
		}
	}

	return cmd;
}