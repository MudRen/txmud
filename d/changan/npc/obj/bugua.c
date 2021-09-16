// bugua.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("破布褂", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一件洗得发白的破布褂。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
