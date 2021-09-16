// armor.c

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("�����", ({ "armor" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "iron");
		set("value", 5000);
		set("armor_prop/armor", 35);
		set("armor_prop/dodge", -2);
	}
	setup();
}
