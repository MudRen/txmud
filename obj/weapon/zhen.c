// zhen.c

// 针归类于暗器，单拿出来没什么意义，
// 就是明教好像也就一个叫什么的变态
// 用，普遍意义上讲为暗器。combined.

// Modified by Find.

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("细针", ({ "zhen" }) );
	if( clonep() )
	set_default_object(__FILE__);

	else
	{
		set("base_weight", 50);
		set("base_unit", "根");
		set("unit","些");
		set("long", "这是一根看起相当普通的细针，份量大约有几钱左右。\n");
		set("base_value", 10);
		set("material", "steel");
		set("wield_msg", "$N悄悄地从怀里摸出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n小心翼翼的放入怀里的针盒。\n");
	}

	set_amount(1);
	init_throwing(15);
	setup();
}