// skills.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/usr/skills"->main(me,arg);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : skills [<ĳ��>]

���ָ����������ѯ����ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ�������ϵ�Ķ���
�� skills ���Բ�֪�Է��ļ���״����

HELP
    );
    return 1;
}
