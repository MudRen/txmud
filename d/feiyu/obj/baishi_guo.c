// baishi_guo.c

inherit ITEM;

void create()
{
	set_name("百实果", ({ "baishi guo" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一枚百实果。\n");
		set("unit", "枚");
		set("value", 1);
	}
}
