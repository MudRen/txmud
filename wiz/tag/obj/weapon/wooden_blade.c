#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("木刀", ({ "wooden blade" }) );
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "把");
                set("long", "这是一柄木刀，不过刃削得很锋利。\n");
                set("value", 1000);
                set("material", "wood");
                set("wield_msg", "$N握住了手中的$n。\n");
                set("unwield_msg", "$N松开了手中的$n。\n");
        }

        init_blade(10);
        setup();
}
