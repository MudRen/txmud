// buyun_cao.c

inherit ITEM;

void create()
{
	set_name("步云草", ({ "buyun cao" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一颗步云草。\n");
		set("unit", "颗");
		set("value", 1);
	}
}
