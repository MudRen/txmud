// hp cmds (Mon  09-04-95)
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/usr/hp"->main(me,arg);
}
 
int help(object me)
{
	write(@HELP
指令格式 : hp
           hp <对象名称>                   (巫师专用)
 
这个指令可以显示你(□)或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}
