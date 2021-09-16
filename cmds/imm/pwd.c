// pwd.c
// Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object who = me;

	if( stringp(arg) && (wiz_level(me) >= wiz_level("(arch)")) )
	{
		who = present(arg,environment(me));
		if(!who || !userp(who))
			return notify_fail("你要察看谁的情况？\n");
	}

	write("Cwd: " + (string)who->query("cwd") +  "\n");
	write("Cwf: " + (string)who->query("cwf") +  "\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : pwd
 
这个指令会显示出你目前的工作目录 (cwd) 及工作档案 (cwf).
'update' 不加参数时便会更新你的 cwf.
 
HELP
    );
    return 1;
}
