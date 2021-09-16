#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("木剑", ({ "wooden sword" }) );
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "把");
                set("long", "这是一把木剑，不过刃削得很锋利。\n");
                set("value", 1000);
                set("material", "wood");
                set("wield_msg", "$N握住了手中的$n。\n");
                set("unwield_msg", "$N松开了手中的$n。\n");
        }

        init_sword(10);
        setup();
}
