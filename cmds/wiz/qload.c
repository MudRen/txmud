// qload.c
// Modified by Find.

inherit F_CLEAN_UP;

int main()
{
	float cmds,comp;

	sscanf(query_load_average(),"%f cmds/s, %f comp lines/s",cmds,comp);

	write(sprintf("平均每秒接受 %.2f 条使用者命令，每秒编译 %.2f 行程序。\n",
		cmds,comp));

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : qload 

这个指令显示出目前 CPU 的负担。
HELP
    );
    return 1;
}
