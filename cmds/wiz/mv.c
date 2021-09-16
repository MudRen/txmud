// mv.c
// Modified by Find.
 
inherit F_CLEAN_UP;

private void confirm(string yn,string src,string dst); // by Find.

int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
        notify_fail("ָ���ʽ: mv <ԭ����> <Ŀ�굵��> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
 
// added by Find.
	if(file_size(src) < 0)
		return notify_fail("ԭ���������ڡ�\n");
	if(src == dst)  // ��ʹϵͳ����
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
	        if( !rename(src, dst) )
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
		if( !rename(src, dst) )
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
ָ���ʽ : mv <ԭ����> <Ŀ�굵��>
 
��ָ��������޸�ĳ��������Ŀ¼���ơ�
HELP
    );
    return 1;
}