// chicken_leg.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������", ({ "ji tui", "leg" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������������ļ��ȡ�\n");
		set("unit", "��");
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
	set_name("�еþ���ļ��ȹ�ͷ", ({ "bone" }) );
	set_weight(150);
	set("long", "һ���еþ���ļ��ȹ�ͷ��\n");
	return 1;
}
