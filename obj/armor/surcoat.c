// surcoat.c

#include <armor.h>

inherit SURCOAT;

void create()
{
	set_name("����", ({ "surcoat","coat" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",2000);
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}