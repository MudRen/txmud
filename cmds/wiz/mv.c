// mv.c
// Modified by Find.
 
inherit F_CLEAN_UP;

private void confirm(string yn,string src,string dst); // by Find.

int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
        notify_fail("指令格式: mv <原档名> <目标档名> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
 
// added by Find.
	if(file_size(src) < 0)
		return notify_fail("原档案不存在。\n");
	if(src == dst)  // 会使系统报错。
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
	        if( !rename(src, dst) )
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
		if( !rename(src, dst) )
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
指令格式 : mv <原档名> <目标档名>
 
此指令可让你修改某个档案或目录名称。
HELP
    );
    return 1;
}