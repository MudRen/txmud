// hujia.c

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("ţƤ����", ({ "niupi hujia" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "skin");
		set("value", 2000);
		set("armor_prop/armor", 25);
		set("armor_prop/dodge", -1);
	}
	setup();
}
