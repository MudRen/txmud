#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIY"耳环"NOR, ({ "er huan" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一对小巧精致的耳环。\n");
                set("unit", "对");
                set("value", 10000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 2);
                set("wear_msg", "$N轻轻地把一个$n戴在耳朵上。\n");
                set("unwield_msg", "$N轻轻地把$n从耳朵上除了下来。\n");
        }
        setup();
}
