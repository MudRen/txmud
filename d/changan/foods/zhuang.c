// zhuang.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("״Ԫ��", ({ "zhuang yuan hong" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "̳");
		set("value", 1);
		set("material","glass");
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "״Ԫ���",
		"remaining": 6,
		"drunk_apply": 5,
	]) );
}
