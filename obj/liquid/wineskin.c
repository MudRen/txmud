// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ţƤ�ƴ�", ({ "jiu dai" }) );
	set_weight(700);
	if( clonep() ) {
			set("liquid", ([
			"apply_condition": "drunk",
			"condition_count": 10,
			"name": "���",
			"remaining": 15,
			"drunk_apply": 15,
		]) );
		set_default_object(__FILE__);
	} else {
		set("long", "һ��ţƤ��Ĵ�ƴ������װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}
}
