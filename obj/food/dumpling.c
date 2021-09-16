// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("包子", ({ "baozi", "dumpling" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷、热腾腾的大包子。\n");
		set("unit", "个");
		set("value", 40);
		set("food_remaining", 3);
		set("food_supply", 10);
	}
}
