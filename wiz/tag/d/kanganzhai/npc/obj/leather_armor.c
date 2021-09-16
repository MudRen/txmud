// leather_armor.c

#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("皮甲", ({ "leather armor" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件结实的皮甲，看来造好已经有些年月了。\n");
                set("unit", "件");
                set("value", 4000);
                set("material", "leather");
                set("armor_prop/armor", 30);
        }
        setup();
}

