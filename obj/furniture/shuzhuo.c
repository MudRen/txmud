// shuzhuo.c

inherit ITEM;

void create()
{
	set_name("红木书桌", ({ "shu zhuo" }) );

	set_weight(300);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("no_get",1);
		set("unit", "张");
		set("long", "这是一张漆得可以照见人的红木书桌。\n");
		set("value", 100000);
		set("material", "wood");
	}
	setup();
}