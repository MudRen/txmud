// maotai.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ę́", ({ "mao tai" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ƿ");
		set("value", 1);
		set("material","glass");
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "ę́��",
		"remaining": 6,
		"drunk_apply": 10,
	]) );
}
