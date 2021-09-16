//inventory.c
// 装备于右手的兵器用'○'标示.
// Modified by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/usr/inventory"->main(me,arg);
}

int help (object me)
{
        write(@HELP
指令格式: inventory
 
可列出你目前身上所携带的所有物品。

"□" 标记说明此物品为你已经装备
     的兵器或者已穿戴的护甲。
"○" 标记说明此兵器装备于你的左手。

注 : 此指令可以 " i " 代替。
 
HELP
);
        return 1;
}
