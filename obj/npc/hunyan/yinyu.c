// yinyu.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����", ({ "yin yu"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��˫ϲ�������Ƶ��������
������������ࡱ��\n");
		set("unit", "��");
		set("value", 1);
		set("food_remaining", 5);
		set("food_supply", 10);
		set("hun_food", 1);
	}
	setup();
}
