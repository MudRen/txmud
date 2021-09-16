// rope.c

#include <weapon.h>

inherit WHIP;

void create()
{
	set_name( "皮鞭", ({ "whip" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "条");
		set("long", "这是一条看起相当普通的皮鞭。\n");
		set("material", "skin");
		set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n束在腰间。\n");
	}

	init_whip(10);
	setup();
}