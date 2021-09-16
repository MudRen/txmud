// gao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("花生枣糕", ({ "zao gao"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "由双喜阁精心烹制的花生枣糕，
又名“早生贵子”。\n");
		set("unit", "份");
		set("value", 1);
		set("food_remaining", 5);
		set("food_supply", 10);
	}
	setup();
}