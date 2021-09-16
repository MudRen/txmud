#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name(HIR"戒指"NOR, ({ "jie zhi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个小巧精致的戒指。\n");
                set("unit", "个");
                set("value", 20000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 1);
                set("wear_msg", "$N轻轻地把一个$n戴在手指上。\n");
                set("unwield_msg", "$N轻轻地把$n从手指上除了下来。\n");
        }
        setup();
}
