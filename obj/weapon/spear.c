// spear.c

#include <weapon.h>

inherit SPEAR;

void create()
{
	set_name( "长枪", ({ "spear" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "枝");
		set("long", "一枝银色两丈多的长枪。\n");
		set("material", "iron");
		set("wield_msg", "$N拿起一枝$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");                
	}

	init_fork(20);
	setup();
}