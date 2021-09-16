// tail.c
// by Find.

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file,content,*output;
	int n = 24,i;

	seteuid(geteuid(me));
	if(!arg)
		return help(me);

	if(sscanf(arg,"-%d %s",n, arg) == 2)
		if(n<1)
			n = 1;

	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 )
		return notify_fail("û�����������\n");

	if(!content = read_file(file))
		return notify_fail("��û�ж�ȡ����������ݵ�Ȩ�ޡ�\n");

	output = explode(content,"\n");
	i = sizeof(output);

	me->start_more(implode(output[(i>n?i-n:0)..],"\n")+"\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ :

tail <����>

��ָ�������ֱ�Ӷ�ȡĳ������ĩβ�ļ��С�

tail -n <����>

��ָ�������ֱ�Ӷ�ȡĳ������ĩβ�� n �С�(n Ϊ������)

HELP
    );
    return 1;
}
