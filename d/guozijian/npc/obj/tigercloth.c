// tigercloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���۳���", ({ "tigercloth", "cloth" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"һ���������л�ͷ�İ�ɫ������\n");
		set("unit", "��");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/intelligence", 2);
	}
	setup();
}

