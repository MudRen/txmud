// hedingh.c
// 用来下毒。
// Find.

inherit POISON;

void create()
{
	set_name("鹤顶红", ({ "he dinghong" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "颗");
		set("long", "这是一颗含有剧毒的鹤顶红。\n");
		set("value", 10000);

		// 能用于下毒的物品必须的设定。
		set("can_use",2);	// 能下两次毒。
		set("apply_poison","he_ding_hong");	// 中毒的 condition.
	}
}
