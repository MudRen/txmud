// doujiang.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("����", ({ "ci wan", "wan", "bowl" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������롣\n");
		set("unit", "��");
		set("value", 100);
		set("material","glass");
		set("max_liquid", 15);
	}


	set("liquid", ([
		"name": "����",
		"remaining": 5,
		"drunk_apply": 15,
	]) );
}