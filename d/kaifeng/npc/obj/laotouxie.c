#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name("老头鞋", ({ "laotou xie" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "这是双质地很好的老头鞋。\n");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

