// set.c
// Modified by Find.
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	return "/cmds/usr/set"->main(me,arg);
}
 
int help()
{
	write(@TEXT
ָ���ʽ��set <������> [<����ֵ>]
 
���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ�����ڶ�ֵΪ "YES"��
 
ȡ�������趨���� unset ָ�
 
�������Щ�������������趨����� help settings��
TEXT
	);
	return 1;
}