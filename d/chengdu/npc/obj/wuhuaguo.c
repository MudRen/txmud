// wuhuaguo.c

inherit ITEM;

protected string master;

void create()
{
	set_name("无花果干", ({ "wu hua guo" }) );
	set_weight(100);
	set("value", 1);
	set("unit", "颗");
	set("long", "这是一颗晒干了的无花果。\n");
}
