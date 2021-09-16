#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name(HIY"黄金项链"NOR, ({ "huangjin xianglian" , "xianglian"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一串价值连城的项链。\n");
                set("unit", "个");
                set("value", 100000);
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 5);
                set("wear_msg", "$N轻轻地把一个$n戴在脖子上。\n");
                set("unwield_msg", "$N轻轻地把$n从脖子上除了下来。\n");

        }
        setup();
}
