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
			write("你没有在这里建子目录的权利。\n");
	}

	else if( status == -2 )
		write("目录已存在。\n");

	else
		write("存在同名文件，无法建立此目录。\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : mkdir <子目录名>

建立一个子目录。
HELP
	);
	return 1;
}