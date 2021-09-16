// dart.c

#include <weapon.h>

inherit THROWING;

int through_armor() { return 1; }

void create()
{
	set_name("透甲锥", ({ "toujia zhui" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一枝闪着寒光的刚锥，专门用来穿透护甲的暗器。\n");
		set("unit", "些");
		set("base_unit", "枝");
		set("base_weight", 100);
		set("base_value", 100);
	}

	set_amount(1);
	init_throwing(20);
	setup();
}
