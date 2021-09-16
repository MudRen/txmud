#include <armor.h>
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"小花球" NOR, ({ "flower ball", "ball" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个五颜六色，非常漂亮的小花球。\n");
                set("unit", "个");
                set("value", 100);
                set("material", "plant");
        }
        setup();
}
