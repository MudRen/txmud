// 设计者:贝塔(bate)
// 时间: 1998/08/25
// xcp.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	string src,dst;
	string src_dir,dst_dir,dir;
	string s_flag,t_flag;
	mixed *file;
	int i, j;
	int ok,nook; 
	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("指令格式: cp <原档名> <目标档名> \n");

	dst = resolve_path(me->query("cwd"), dst);
	for(i=0;i<strlen(dst);i++) {
		if(dst[i] == '*') return notify_fail("现在不支持目标档包含*号.\n");
	}
	if (file_size(dst) != -2) 	return notify_fail("目标目录不存在。\n");
	t_flag = " ";
	if( file_size(dst)==-2) {
		t_flag="/";
		if(dst[strlen(dst)-1] != '/' ) dst += "/";
	}
	file = get_dir(dst, -1);
	src = resolve_path(me->query("cwd"), src);
	s_flag=" ";
	for(i=strlen(src)-1;i>=0;i--) {
		if(src[i] == '/') break;
	}
	dir = src[0..i];
	if( file_size(src)==-2) return notify_fail("你要拷贝什么啊?\n");
	file = get_dir(src, -1);
	if( !sizeof(file) )
	{if (file_size(src) == -2) return notify_fail("你要拷贝什么啊?\n");
		else
		return notify_fail("没有这个目录。\n");
	}
	ok = 0;
	nook = 0;
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++) {
			if( file[i][1] == -2) continue;
			if( t_flag == "/") dst_dir = dst + file[i][0];
			src_dir = dir + file[i][0];
			if( cp(src_dir, dst_dir) ) ok++;
			else nook++;
		}

	printf("你拷贝成功%d个文件,失败%d个文件。\n",ok,nook);
	return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : xpp <原档名> <目标档名>
 
此指令可让你(□)拷贝档案。
HELP
    );
    return 1;
}