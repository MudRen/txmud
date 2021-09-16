#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(WHT"宽刃大柄刀"NOR, ({ "broad blade" }) );
        set_weight(12000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "柄");
                set("long", "这是一柄硕大的砍刀，看来没有足够的力量是挥舞不起来的。\n");
                set("value", 6000);
                set("material", "steel");
                set("wield_msg", "$N大喝一声，双手紧紧握住了$n。\n");
                set("unwield_msg", "$N松开了手中的$n。\n");
        }

        init_blade(40);
        setup();
}
