#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name(HIC"翡翠戒指"NOR, ({ "feicui jiezhi" , "jiezhi"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个价值连城的翡翠戒指。\n");
                set("unit", "个");
                set("value", 100000);
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 6);
                set("wear_msg", "$N轻轻地把一个$n戴在手指上。\n");
                set("unwield_msg", "$N轻轻地把$n从手指上除了下来。\n");
        }
        setup();
}
