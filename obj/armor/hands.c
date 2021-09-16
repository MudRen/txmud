// hands.c

#include <armor.h>

inherit HANDS;

void create()
{
	set_name("»¤ÊÖ", ({ "armguard" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","Ë«");
		set("material", "iron");
		set("value", 500);
		set("armor_prop/armor", 1);
	}
	setup();
}