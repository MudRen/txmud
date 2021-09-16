// yinyu.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("银鱼羹", ({ "yin yu"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "由谪仙楼精心烹制的银鱼羹。\n");
		set("unit", "份");
		set("value", 1);
		set("food_remaining", 5);
		set("food_supply", 5);
		set("hun_food", 1);
	}
	setup();
}
