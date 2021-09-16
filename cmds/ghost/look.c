//	/cmds/std/look.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/std/look"->main(me,arg);
}

int help (object me)
{
        write("\n
指令格式: look [<物品>|<生物>|<方向>]
 
这个指令让你查看你所在的环境、某件物品、生物、或是方向。
\n"+
((wizardp(me))? "用 -e 参数可以观察一个人所处的环境，
例如：look -e find , 观察 find 所处的环境。\n\n"
:"")
);
        return 1;
}