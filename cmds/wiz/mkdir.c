// mkdir.c
// Modified by Find.

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string dir;
	int status;

	if(!arg) return help(me);

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));

	status = file_size(dir);
	if(status == -1)
	{
		if( mkdir(dir) )
			write("Ok.\n");
		else
			write("��û�������ｨ��Ŀ¼��Ȩ����\n");
	}

	else if( status == -2 )
		write("Ŀ¼�Ѵ��ڡ�\n");

	else
		write("����ͬ���ļ����޷�������Ŀ¼��\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : mkdir <��Ŀ¼��>

����һ����Ŀ¼��
HELP
	);
	return 1;
}