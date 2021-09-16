// rm.c

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	string full_path;

	seteuid(geteuid(me));
	if(!file)
		return notify_fail("��Ҫɾ���Ǹ�����?\n");

	full_path = resolve_path(me->query("cwd"), file);
	if(file_size(full_path) == -1)
		return notify_fail("û�� "+full_path+" ���������\n");
	if(file_size(full_path) == -2)
		return notify_fail("ɾ��Ŀ¼��ʹ�� rmdir ���\n");
	if( rm(full_path) )
		write("Ok.\n");
	else
		write("��û��ɾ�����������Ȩ����\n");
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : rm <����>

��ָ�������(��)ɾ����Ȩ�޸ĵĵ�����
HELP
    );
    return 1;
}