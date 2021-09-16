// /cmds/usr/build.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if(!arg || arg == "")
		return notify_fail("你要在什么方向建房？\n");

	if(!PLAYERHOME_D->buildup_home(me,arg))
		return notify_fail("建房失败。\n");
	return 1;
}