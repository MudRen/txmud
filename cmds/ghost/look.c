//	/cmds/std/look.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/std/look"->main(me,arg);
}

int help (object me)
{
        write("\n
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
\n"+
((wizardp(me))? "�� -e �������Թ۲�һ���������Ļ�����
���磺look -e find , �۲� find �����Ļ�����\n\n"
:"")
);
        return 1;
}