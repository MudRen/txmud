// cp.c
 
inherit F_CLEAN_UP;

private void confirm(string yn,string src,string dst); // by Find.

int main(object me, string arg)
{
	string src, dst, *dirs;
 
	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("指令格式: cp <原档名> <目标档名> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(dst)==-2 ) {
		dirs = explode(src, "/");
		dst += "/" + dirs[sizeof(dirs)-1];
	}

// added by Find.
	if(src == dst)  // 此后果恶劣。
	{
		write("原档案和目标档案相同，使用非法。\n");
		return 1;
	}

	if(file_size(dst) != -1)
	{
		write("档案 "+dst+" 已存在，是否确定要覆盖？(y/n)");
		input_to("confirm", src, dst);
	}
// end.

	else
	{
		if( cp(src, dst) )
			write("Ok.\n");
		else
			write("你没有足够的读写权利。\n");
	}

	return 1;
}

// added by Find.
private void confirm(string yn,string src,string dst)
{
	if( yn[0..0] != "y" && yn[0..0] != "Y" )
	{
		write("中断操作。\n");
		return;
	}

	else
	{
		if( cp(src, dst) )
			write("Ok.\n");
		else
			write("你没有足够的读写权利。\n");
		return;
	}
}
// end.

int help(object me)
{
  write(@HELP
指令格式 : cp <原档名> <目标档名>
 
此指令可让你拷贝档案。
HELP
    );
    return 1;
}