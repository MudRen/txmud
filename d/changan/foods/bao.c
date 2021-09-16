// bao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("玲珑煎包", ({ "jian bao"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "由谪仙楼精心烹制的玲珑水煎包。\n");
		set("unit", "份");
		set("value", 1);
		set("food_remaining", 5);
		set("food_supply", 5);
	}
	setup();
}
