// baiyun_tang.c

inherit ITEM;

void create()
{
	set_name("百云汤", ({ "baiyun tang" }) );

	set_weight(100);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一剂棕红色的百云汤。\n");
		set("unit", "剂");
		set("value", 1);
	}
}
