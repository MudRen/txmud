// kettle.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���", ({ "kettle" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ���������������Ƕ����и���ߡ�\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 20);
		set("material","glass");
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 8,
                "drunk_apply": 20,

	]) );
}