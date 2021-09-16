// sixhammer.c

#include <weapon.h>

inherit DHAMMER; /* 这是单手锤,可拿一对. by Find.*/

void create()
{
	set_name("六角锤", ({ "sixhammer","hammer" }) );
	set_weight(25000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long", "这是一把六角铜锤，沉甸甸的。\n");
		set("material", "iron");
		set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(25);
        setup();
}