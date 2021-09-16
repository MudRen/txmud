// cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( HIC"青布长衫" NOR, ({ "qingbu cloth" }) );
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "件");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("wear_msg", "$N将$n拿出穿在身上。\n");
	}
	setup();
}
