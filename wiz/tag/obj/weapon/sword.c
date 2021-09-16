#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("长剑", ({ "sword" }) );
        set_weight(4000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "把");
                set("long", "这是一把长剑，是最常见的兵器之一了。");
                set("value", 2500);
                set("material", "iron");
                set("wield_msg", "$N「唰」地拔出一把$n，握在手中。\n");
                set("unwield_msg", "$N「哧」地将$n插回了剑鞘中。\n");
        }

        init_sword(25);
        setup();
}
