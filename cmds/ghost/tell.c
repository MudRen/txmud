// tell.c
// Modified by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/std/tell"->main(me,arg);
}
int help(object me)
{
	write(@HELP
指令格式：tell <某人> <讯息>

你可以用这个指令和其他地方的使用者说话。

其他相关指令：reply
HELP
	);
	return 1;
}
