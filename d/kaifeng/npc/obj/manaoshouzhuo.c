#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name(WHT"玛瑙手镯"NOR, ({ "manao shouzhuo" , "shouzhuo"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个价值连城的玛瑙手镯。\n");
                set("unit", "个");
                set("value", 100000);
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 4);
                set("wear_msg", "$N轻轻地把一个$n戴在手腕上。\n");
                set("unwield_msg", "$N轻轻地把$n从手腕上除了下来。\n");

        }
        setup();
}
