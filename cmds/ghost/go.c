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
ָ���ʽ : go <����>
 
������ָ���ķ����ƶ���
 
HELP
    );
    return 1;
}