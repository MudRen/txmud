// cat.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file,content;
	object ob;

	seteuid(geteuid(me));
	if (!arg) return notify_fail("ָ���ʽ : more <����>|<�����> \n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file) < 0 ) {
		ob = present(arg, me);
		if( !ob ) ob = present(arg, environment(me));
		if( !ob ) return notify_fail("û�����������\n");
		file = base_name(ob) + ".c";
	}

	if(file_size(file) == 0)
		return notify_fail(file+" ��û�����ݵĿյ�����\n");

	if(!content = read_file(file))
		return notify_fail("��û�ж�ȡ���� "+file+" ���ݵ�Ȩ�ޡ�\n");
	me->start_more(content);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : more <����>|<�����>
 
��ҳ��ʾ�������ݡ�
 
more ģʽ�µ�ָ��:
q      : �뿪 more.
b      : ��ʾǰһҳ������.
[ENTER]: ��ʾ��һҳ������.

HELP
    );
    return 1;
}
