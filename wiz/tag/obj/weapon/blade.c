#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("单刀", ({ "blade" }) );
        set_weight(4000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "柄");
                set("long", "这是一柄单刀，是最常见的兵器之一了。");
                set("value", 2500);
                set("material", "iron");
                set("wield_msg", "$N「唰」地拔出一柄$n，握在手中。\n");
                set("unwield_msg", "$N「哧」地将$n插回了刀鞘中。\n");
        }

        init_blade(25);
        setup();
}
