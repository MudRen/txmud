// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ţƤˮ��", ({ "waterskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ţƤ��Ĵ�ƴ������װ�ðˡ���������ˮ��\n");
		set("unit", "��");
		set("value", 200);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"name": "��ˮ",
		"remaining": 10,
		"drunk_apply": 25,
	]) );
}
