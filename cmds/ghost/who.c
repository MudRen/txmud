// who.c
// Modified by Find.

inherit F_CLEAN_UP;

mixed main(object me, string arg, int remote)
{
	return "/cmds/usr/who"->main(me,arg);
}

int help(object me)
{
write(@HELP
指令格式 : who [-l|-i|-w]

这个指令可以列出所有在线上的玩家及其等级。

-l 选项列出较长的讯息。
-w 只列出线上所有的巫师。

相关指令： finger
HELP
    );
    return 1;
}