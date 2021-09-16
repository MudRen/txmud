// mangpao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("蟒袍", ({ "mang pao", "pao" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","这是一件掐金走银的青龙蟒袍。\n");
		set("unit", "件");
		set("value",10000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
