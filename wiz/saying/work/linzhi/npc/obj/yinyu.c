// yinyu.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����", ({ "yinyu"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "������¥�������Ƶ��������\n");
		set("unit", "��");
		set("value", 2000);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
	setup();
}