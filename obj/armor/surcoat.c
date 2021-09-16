// surcoat.c

#include <armor.h>

inherit SURCOAT;

void create()
{
	set_name("ÍâÌ×", ({ "surcoat","coat" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",2000);
		set("unit", "¼þ");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}