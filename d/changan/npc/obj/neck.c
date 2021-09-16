// neck.c

#include <armor.h>

inherit NECK;

void create()
{
	set_name("Å£Æ¤¾±»·", ({ "neck armor", "neck" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","¸±");
		set("material", "iron");
		set("value", 2500);
		set("armor_prop/armor", 30);
	}
	setup();
}
