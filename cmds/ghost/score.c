// score.c
// by Find.

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	return "/cmds/usr/score"->main(me,arg);
}

int help(object me)
{
	write("ָ���ʽ : score\n"
+((wizardp(me))?"           score <��������>\n\n":"\n")
+"���ָ�������ʾ��"+((wizardp(me))?"��ָ������(������)":"")+"�Ļ������ϡ�\n"
+"see also : hp\n");
    return 1;
}