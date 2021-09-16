// guanfu.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("七品官服", ({ "guan fu", "fu" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","这是一件七品官服。\n");
		set("unit", "件");
		set("value",2000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
