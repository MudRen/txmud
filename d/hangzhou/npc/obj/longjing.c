// longjing.c

inherit ITEM;

void create()
{
	set_name("西湖龙井茶", ({ "xihu longjing" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一包杭州名产-龙井茶。\n");
		set("unit", "包");
		set("value", 100);
	}
}
