// help.c
// Modified by Find.

#include <help.h>

inherit F_CLEAN_UP;

nomask int main(object me, string arg)
{
	int i,j;
	string file, *search,*sub_path;
	string *default_search = wizardp(me)?WIZ_DEFAULT_SEARCH_PATHS:USR_DEFAULT_SEARCH_PATHS;

	if(wizardp(me))
		seteuid(geteuid(me));

	// If no topic specified, give the topics.
	if( !arg ) {
		me->start_more(read_file(HELP_DIR + "help/topics"));
		return 1;
	}

	// Else, try if a command name is specified.
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("�����ָ����ڣ����ǲ�û����ϸ��˵���ļ���\n");
		return file->help(me);
	}

	// Search the individual search path first.
	if( pointerp(search = me->query("help_search_path")) && wizardp(me))
	{
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more( read_file(search[i] + arg) );
			return 1;
		}
	}

	// Support efun/lfun help with same name as other topics such as
	// ed() and ed command.
	sscanf(arg, "%s()", arg);

	// Finally, search the default search paths.
	if( pointerp(default_search) )
	{
		i = sizeof(default_search);
		while(i--)
		{
			if( file_size(default_search[i] + arg)>0 )
			{
				me->start_more( read_file(default_search[i] + arg) );
				return 1;
			}
			reset_eval_cost();
			sub_path = get_dir(default_search[i]);
			for(j=0;j<sizeof(sub_path);j++)
			{
				if(file_size(default_search[i] +sub_path[j]) == -2 )
				{
					if( file_size(default_search[i] + sub_path[j]+"/"+arg)>0 )
					{
						me->start_more( read_file(default_search[i]+sub_path[j]+"/" + arg) );
						return 1;
					}
				}
			}
		}
	}

	return notify_fail("û��������������˵���ļ���\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ��help <����>              ���磺> help cmds
	  help <��������>()        ���磺> help call_out()

���ָ���ṩ�����ĳһ�������ϸ˵���ļ������ǲ�ָ�����⣬���ṩ���й�
������ļ���
HELP
	);
	return 1;
}

