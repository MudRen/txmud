// boot.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("�鲼ѥ", ({ "ma bu shoes" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","˫");
		set("material", "cloth");
		set("value", 200);
		set("armor_prop/armor", 20);
	}
	setup();
}
