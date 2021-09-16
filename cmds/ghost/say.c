// say.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/std/say"->main(me,arg);
}

int help (object me)
{
	write(@HELP
指令格式: say <讯息>
 
说话，所有跟你在同一个房间的人都会听到你说的话。
 
注: 本指令可用 ' 取代.
 
HELP
	);
	return 1;
}
