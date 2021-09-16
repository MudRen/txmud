// neck.c

#include <armor.h>

inherit NECK;

void create()
{
	set_name("»¤¾±", ({ "neck armor", "neck" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","¸±");
		set("material", "iron");
		set("value", 500);
		set("armor_prop/armor", 2);
	}
	setup();
}