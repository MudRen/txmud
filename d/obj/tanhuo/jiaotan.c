// 木炭 mutan
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"焦炭"NOR, ({ "jiao tan" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一颗很普通的焦炭，用于铸造时的辅料。\n");
		set("unit", "颗");
		set("value", 3000);
	}
}