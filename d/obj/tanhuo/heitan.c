// 黑炭 mutan
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"黑炭"NOR, ({ "hei tan" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一颗普通的黑炭，用于铸造时的辅料。\n");
		set("unit", "颗");
		set("value", 5000);
	}
}