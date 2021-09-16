// chicken_leg.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("烤鸡腿", ({ "ji tui", "leg" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根烤得香喷喷的鸡腿。\n");
		set("unit", "根");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 20);
		set("material", "bone");
		set("hun_food", 1);
	}
	setup();
}

int finish_eat()
{
	set_name("啃得精光的鸡腿骨头", ({ "bone" }) );
	set_weight(150);
	set("long", "一根啃得精光的鸡腿骨头。\n");
	return 1;
}
