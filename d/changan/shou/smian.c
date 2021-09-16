// smian.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("寿面", ({ "shou mian"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "由谪仙楼精心制作的寿面。\n");
		set("unit", "份");
		set("value", 1);
		set("food_remaining", 5);
		set("food_supply", 5);
	}
	setup();
}
