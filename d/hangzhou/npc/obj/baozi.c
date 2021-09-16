// baozi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("小笼汤包", ({ "baozi" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一只精巧的小笼汤包。\n");
		set("unit", "只");
		set("value", 40);
		set("food_remaining", 3);
		set("food_supply", 10);
	}
}
