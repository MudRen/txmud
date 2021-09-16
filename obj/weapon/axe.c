// axe.c

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("铁斧", ({ "axe" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long", "这是一把沈重的铁斧。\n");
		set("material","iron");
		set("wield_msg", "$N拿出一把$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_axe(30);
	setup();
}