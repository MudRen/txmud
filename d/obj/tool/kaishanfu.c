// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("开山斧", ({ "kai shan fu" }) );
	set_weight(8000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一把伐木工常用的开山斧。\n");
		set("unit", "把");
		set("value", 1000);
	}
}