// kickout.c
// Modified by Find.

#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob,login_ob;
	string wiz_status;

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s", arg)!=1 )
		return notify_fail("argument error!\n");

	wiz_status=SECURITY_D->get_status(me) ;

	if(wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("You didn't have this right!\n");

	ob = LOGIN_D->find_body(arg);

	if(!ob)
		return notify_fail("咦... 有这个人吗?\n");
	if( /*!living(ob)
	|| !ob->is_character()
	|| */ ob==me )
		return notify_fail("ob error!\n");

	message_vision( "\n$N大喊一声“看你敢再淘气！”一脚将$n踢了出去！！\n\n", me,ob);

	login_ob = ob->query_temp("link_ob");

	seteuid(ROOT_UID);
        ob->save();
	if(login_ob)
	{
		login_ob->save();
		destruct(login_ob);
	}
        destruct(ob);
	seteuid(getuid());

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : kickout <某人>

HELP
    );
    return 1;
}