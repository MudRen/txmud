// taxue.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("̤ѩѰ��", ({ "ta xue"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "������¥�������Ƶ�̤ѩѰ�ܡ�\n");
		set("unit", "��");
		set("value", 1);
		set("food_remaining", 5);
		set("food_supply", 5);
		set("hun_food", 1);
	}
	setup();
}
