// douya.c

inherit ITEM;

void create()
{
	set_name("豆芽菜", ({ "bean" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一把新鲜的豆芽菜。\n");
		set("unit", "把");
		set("value", 50);
	}
}
