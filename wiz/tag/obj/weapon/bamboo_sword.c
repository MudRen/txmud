#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("竹剑", ({ "bamboo sword" }) );
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "把");
                set("long", "这是一把练习剑法用的竹剑，剑尖处用布包了起来以免误伤同伴。\n");
                set("value", 500);
                set("material", "bamboo");
                set("wield_msg", "$N握住了手中的$n。\n");
                set("unwield_msg", "$N松开了手中的$n。\n");
        }

        init_sword(5);
        setup();
}
