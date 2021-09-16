// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("牛皮水袋", ({ "waterskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个牛皮缝的大酒袋，大概装得八、九升的清水。\n");
		set("unit", "个");
		set("value", 200);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"name": "清水",
		"remaining": 10,
		"drunk_apply": 25,
	]) );
}
