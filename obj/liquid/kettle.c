// kettle.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("茶壶", ({ "kettle" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一个短嘴儿茶壶，壶盖儿上有个金边。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 20);
		set("material","glass");
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "茶水",
		"remaining": 8,
                "drunk_apply": 20,

	]) );
}