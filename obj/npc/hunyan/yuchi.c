// yuchi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("飞花鱼翅", ({ "yu chi"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "由双喜阁精心烹制的飞花鱼翅，
又名“比翼双飞”。\n");
		set("unit", "份");
		set("value", 1);
		set("food_remaining", 5);
		set("food_supply", 10);
		set("hun_food", 1);
	}
	setup();
}
