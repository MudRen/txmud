// go.c
// Modified by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/std/go"->main(me,arg);
}

int help(object me)
{
        write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP
    );
    return 1;
}