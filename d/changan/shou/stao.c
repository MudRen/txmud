// stao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({ "shou tao"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "������¥�������Ƶ����ҡ�\n");
		set("unit", "��");
		set("value", 1);
		set("food_remaining", 5);
		set("food_supply", 5);
	}
	setup();
}
