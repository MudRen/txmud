// baozi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("С������", ({ "baozi" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һֻ���ɵ�С��������\n");
		set("unit", "ֻ");
		set("value", 40);
		set("food_remaining", 3);
		set("food_supply", 10);
	}
}
