// hands.c

#include <armor.h>

inherit HANDS;

void create()
{
	set_name("����", ({ "hu shou" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","˫");
		set("material", "iron");
		set("value", 500);
		set("armor_prop/armor", 25);
	}
	setup();
}
