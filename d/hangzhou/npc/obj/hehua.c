// hehua.c

inherit ITEM;

void create()
{
	set_name("荷花", ({ "water lily" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一枝洁白的荷花。\n");
		set("unit", "枝");
		set("value", 100);
	}
}
