// nver.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("Å®¶ùºì", ({ "nv er hong" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ì³");
		set("value", 1);
		set("material","glass");
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "Å®¶ùºì¾Æ",
		"remaining": 6,
		"drunk_apply": 10,
	]) );
}
