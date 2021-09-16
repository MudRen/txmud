// tangforce.c
// 一个可下毒的内功的例子
// by Find.

inherit FORCE;


// 下毒函数
void drug_in_object()
{
	if(this_player())
		this_player()->apply_condition("tangdu",
			this_player()->query_condition("tangdu")+10);

	// 返回值一律为零，以便于不会影响其它的效果产生。
	return;
}

// 此玩家可否用此武功下毒
int valid_xiadu(
	object me,  /* 下毒动作者 */
	int level   /* 下毒动作者此项武功的等级 */
)
{
	if(intp(level) && level > 500)
		return 1;
	else
		return notify_fail("你的唐毒等级没有500，没法下毒。\n");
}