// say.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/std/say"->main(me,arg);
}

int help (object me)
{
	write(@HELP
ָ���ʽ: say <ѶϢ>
 
˵�������и�����ͬһ��������˶���������˵�Ļ���
 
ע: ��ָ����� ' ȡ��.
 
HELP
	);
	return 1;
}
