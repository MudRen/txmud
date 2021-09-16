// bowl.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("����", ({ "ci wan" }) );
	set_weight(700);
	if( clonep() ) {
		set("liquid", ([
			"apply_condition": "drunk",
			"condition_count": 10,
			"name": "���",
			"remaining": 5,
			"drunk_apply": 15,
		]) );
		set_default_object(__FILE__);
	} else {
		set("long", "һ������롣\n");
		set("unit", "��");
		set("value", 100);
		set("material","glass");
		set("max_liquid", 15);
	}
}
