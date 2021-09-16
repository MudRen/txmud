#include <weapon.h>
inherit STICK;

void create()
{
        set_name("竹棍", ({ "bamboo stick" }) );
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "根");
                set("long", "这是一把练习棍法用的竹棍。\n");
                set("value", 500);
                set("material", "bamboo");
                set("wield_msg", "$N握住了手中的$n。\n");
                set("unwield_msg", "$N松开了手中的$n。\n");
        }

        init_stick(5);
        setup();
}
