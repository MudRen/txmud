// skirt.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIM"喜红长裙"NOR, ({ "red happy skirt", "skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一条粉红色的长裙，上面还缀着几个红色的喜字。\n");
		set("unit", "件");
		set("value", 5);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}