// pwd.c
// Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object who = me;

	if( stringp(arg) && (wiz_level(me) >= wiz_level("(arch)")) )
	{
		who = present(arg,environment(me));
		if(!who || !userp(who))
			return notify_fail("��Ҫ�쿴˭�������\n");
	}

	write("Cwd: " + (string)who->query("cwd") +  "\n");
	write("Cwf: " + (string)who->query("cwf") +  "\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : pwd
 
���ָ�����ʾ����Ŀǰ�Ĺ���Ŀ¼ (cwd) ���������� (cwf).
'update' ���Ӳ���ʱ��������� cwf.
 
HELP
    );
    return 1;
}
