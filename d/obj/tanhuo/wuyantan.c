// 无烟炭 wuyantan
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"无烟炭"NOR, ({ "wuyan tan" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一颗很贵重的无烟炭，用于铸造时的辅料。\n");
		set("unit", "颗");
		set("value", 10000);
	}
}