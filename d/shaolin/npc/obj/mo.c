// pear.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��", ({ "mo" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������������ɡ�\n");
		set("unit", "��");
		set("food_remaining", 4);
		set("food_supply", 30);
	}
	setup();
}