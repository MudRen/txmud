// testid.c
// by 发现号(find).

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string sb,sth;
	object who,obj;
	string euid,uid;

	if(!arg) return notify_fail("testid obj || help testid .\n");

	if( sscanf(arg,"%s %s",sb,sth) == 2)
	{
		if( who = present(sb,me) || who = present(sb,environment(me)) )
		{
			if( obj = present(sth,who))
			{
				euid = geteuid(obj);
				if(obj->query_wiz_flag())
					euid = HIG+euid+NOR;
				write(sprintf("%s(%s) 's euid is: %s\n",sth,base_name(obj),euid));
				return 1;
			}
			else
			{
				write("No this object err.\n");
				return 1;
			}
		}

	}

	if(arg == "here")
		obj = environment(me);

	else if( !obj = present(arg,me) )
		obj = present(arg,environment(me));
	if(!obj)
		obj = find_object(me->query("cwd")+arg);
	if(!obj)
		return notify_fail("No this obj err.\n");


	euid = geteuid(obj);
	uid = getuid(obj);
	if(obj->query_wiz_flag())
	{
		euid = HIG+euid+NOR;
		 uid = HIG+uid+NOR;
	}
	write( sprintf("%s(%s) 's euid : %s, uid : %s.\n",arg,base_name(obj),euid,uid) );

	return 1;
}

int help (object me)
{
	if(!wizardp(me)) return 0;

        write(@HELP
指令格式:

testid here
测试你所处环境的 euid。

testid <obj>
测试你身上或所处环境里物件的 euid。

testid <obj ob>
测试你所处环境里的物件的身上的物件 euid。

此命令可以检查出被检查物件的文件名和 euid。

		by 发现号(find).
HELP
);
        return 1;
}