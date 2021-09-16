#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name(CYN"手镯"NOR, ({ "shou zhuo" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个小巧精致的手镯。\n");
                set("unit", "个");
                set("value", 15000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 1);
                set("wear_msg", "$N轻轻地把一个$n戴在手腕上。\n");
                set("unwield_msg", "$N轻轻地把$n从手腕上除了下来。\n");
        }
        setup();
}

