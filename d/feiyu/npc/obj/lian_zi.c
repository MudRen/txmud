// lian_zi.c

inherit ITEM;

void create()
{
	set_name("莲子", ({ "lian zi" }) );

	set_weight(100);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一颗青皮大莲子。\n");
		set("unit", "颗");
		set("value", 1);
	}
}
