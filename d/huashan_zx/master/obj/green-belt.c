#include <ansi.h>

#include <armor.h>
inherit WAIST;

void create()
{                              
	set_name(HIG"绿丝带" NOR, ({"green belt","belt"}) );
	set_weight(500);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一条丝绸制的腰带，质感很好，
上绣了几朵枫叶。\n");
		set("unit", "条");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 20);
		set("wear_msg", "$N将$n拿出系在腰上。\n");
	}
	setup();
}
