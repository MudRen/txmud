// armor.c

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("ţƤ����", ({ "armor" }) );

	set_weight(1000);

	if( clonep() )
		set_default_object(__FILE__);

	else
	{
		set("unit", "��");
		set("material", "gold");
		set("value", 800);
		set("armor_prop/armor", 20);
                set("armor_prop/dodge", -3);
	}
	setup();
}
