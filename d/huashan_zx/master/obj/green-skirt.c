#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name( HIG "绿罗裙" NOR, ({ "green skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
        else {
		set("unit", "件");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("wear_msg", "$N将$n拿出穿在身上。\n");
		set("female_only", 1);
	}
	setup();
}
