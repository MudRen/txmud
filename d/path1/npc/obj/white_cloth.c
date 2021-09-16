// white_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("白布褂", ({ "white cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件普通的白布褂。\n");
		set("unit", "件");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	setup();
}