// boot.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("��Ь", ({ "shoes" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","˫");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
