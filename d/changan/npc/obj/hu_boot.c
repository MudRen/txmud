// hu_boot.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("��Ƥѥ", ({ "shoes" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","˫");
		set("material", "skin");
		set("value", 1000);
		set("armor_prop/armor", 20);
	}
	setup();
}
