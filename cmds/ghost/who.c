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
ָ���ʽ : who [-l|-i|-w]

���ָ������г����������ϵ���Ҽ���ȼ���

-l ѡ���г��ϳ���ѶϢ��
-w ֻ�г��������е���ʦ��

���ָ� finger
HELP
    );
    return 1;
}