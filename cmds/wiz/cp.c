// cp.c
 
inherit F_CLEAN_UP;

private void confirm(string yn,string src,string dst); // by Find.

int main(object me, string arg)
{
	string src, dst, *dirs;
 
	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("ָ���ʽ: cp <ԭ����> <Ŀ�굵��> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(dst)==-2 ) {
		dirs = explode(src, "/");
		dst += "/" + dirs[sizeof(dirs)-1];
	}

// added by Find.
	if(src == dst)  // �˺�����ӡ�
	{
		write("ԭ������Ŀ�굵����ͬ��ʹ�÷Ƿ���\n");
		return 1;
	}

	if(file_size(dst) != -1)
	{
		write("���� "+dst+" �Ѵ��ڣ��Ƿ�ȷ��Ҫ���ǣ�(y/n)");
		input_to("confirm", src, dst);
	}
// end.

	else
	{
		if( cp(src, dst) )
			write("Ok.\n");
		else
			write("��û���㹻�Ķ�дȨ����\n");
	}

	return 1;
}

// added by Find.
private void confirm(string yn,string src,string dst)
{
	if( yn[0..0] != "y" && yn[0..0] != "Y" )
	{
		write("�жϲ�����\n");
		return;
	}

	else
	{
		if( cp(src, dst) )
			write("Ok.\n");
		else
			write("��û���㹻�Ķ�дȨ����\n");
		return;
	}
}
// end.

int help(object me)
{
  write(@HELP
ָ���ʽ : cp <ԭ����> <Ŀ�굵��>
 
��ָ������㿽��������
HELP
    );
    return 1;
}