// hands.c

#include <armor.h>

inherit HANDS;

void create()
{
	set_name("����", ({ "armguard" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","˫");
		set("material", "iron");
		set("value", 500);
		set("armor_prop/armor", 20);
	}
	setup();
}
