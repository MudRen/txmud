// hp cmds (Mon  09-04-95)
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/usr/hp"->main(me,arg);
}
 
int help(object me)
{
	write(@HELP
ָ���ʽ : hp
           hp <��������>                   (��ʦר��)
 
���ָ�������ʾ��(��)��ָ������(������)�ľ�, ��, ����ֵ��
 
see also : score
HELP
    );
    return 1;
}
