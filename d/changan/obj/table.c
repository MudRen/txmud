// table.c

inherit ITEM;

int is_sxg() { return 1; }

void create()
{
	set_name("红木大餐桌", ({ "double happy table"}) );

	set_weight(5000000);
	set_max_encumbrance(800000);

	set("no_get", 1);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("position", "on");
		set("prep", "on");
		set("unit", "张");
		set("long", "这是一张红木长条大餐桌，足够
几十个人同时吃饭。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }
