// shizi_tou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����ʨ��ͷ", ({ "shizi tou"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "������¥�������Ƶĺ���ʨ��ͷ��\n");
		set("unit", "��");
		set("value", 2000);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
	setup();
}