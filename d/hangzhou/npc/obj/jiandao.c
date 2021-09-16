// jiandao.c

#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("张小泉剪刀", ({ "jian dao" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long", "这是一把杭州名产张小泉剪刀。\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N从怀中摸出一把锃亮的$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n藏入怀中。\n");	
	}

	init_dagger(10);
	setup();
}