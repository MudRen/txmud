// 白炭 wuyantan
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"白炭"NOR, ({ "bai tan" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一颗很贵重的白炭，用于铸造高硬材料的辅料。\n");
		set("unit", "颗");
		set("value", 100000);
	}
}