// rm.c

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	string full_path;

	seteuid(geteuid(me));
	if(!file)
		return notify_fail("你要删除那个档案?\n");

	full_path = resolve_path(me->query("cwd"), file);
	if(file_size(full_path) == -1)
		return notify_fail("没有 "+full_path+" 这个档案。\n");
	if(file_size(full_path) == -2)
		return notify_fail("删除目录请使用 rmdir 命令。\n");
	if( rm(full_path) )
		write("Ok.\n");
	else
		write("你没有删除这个档案的权利。\n");
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : rm <档名>

此指令可让你(□)删除有权修改的档案。
HELP
    );
    return 1;
}