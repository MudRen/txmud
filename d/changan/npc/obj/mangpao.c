// mangpao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("����", ({ "mang pao", "pao" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","����һ�������������������ۡ�\n");
		set("unit", "��");
		set("value",10000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
