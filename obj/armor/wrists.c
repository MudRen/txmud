// wrists.c

#include <armor.h>

inherit WRISTS;

void create()
{
	set_name("����", ({ "wrists" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("value",200);
		set("material", "iron");
		set("armor_prop/armor", 1);
	}
	setup();
}
