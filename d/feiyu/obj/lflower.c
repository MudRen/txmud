#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(  BLU"小蓝花" NOR, ({ "blue flower", "flower" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一朵通体纯蓝的奇异小花，细看之下，却像一瓣奇异的花瓣。\n");
                set("unit", "朵");
                set("value", 1);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 1);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");

        }
        setup();
}

