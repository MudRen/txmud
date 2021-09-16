// wumu_stick.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("乌木长棍", ({ "wumu gun", "gun" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "根");
		set("long", "这是一通体乌黑的长棍。");
		set("value", 300);
		set("material", "wood");
		set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}

	init_staff(20);
	setup();
}