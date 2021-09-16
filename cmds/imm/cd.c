// cd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dir;

	if( !arg )
		arg = user_path(geteuid(me));
	dir = resolve_path(me->query("cwd"), arg);
	if(file_size(dir)!=-2) return notify_fail("û�����Ŀ¼��\n");

	if(dir[strlen(dir)-1]!='/') dir += "/";

// added by Find.
        if(dir == "/syslog/" && wiz_level(me) < wiz_level("(arch)"))
                return notify_fail("û�����Ŀ¼��\n");
// end.

	me->set("cwd", dir);
	write(dir + "\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
ָ���ʽ : cd <��Ŀ¼��>, cd .. , and cd

��Ŀǰ�ο���Ŀ¼����ָ������Ŀ¼��ص���һ��Ŀ¼; ���ֱ�ӻص��Լ�����Ŀ¼��
HELP
	);
	return 1;
}
