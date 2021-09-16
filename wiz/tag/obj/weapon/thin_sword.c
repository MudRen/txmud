#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("细剑", ({ "thin sword" }) );
        set_weight(2500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "把");
                set("long", "这是一把细剑，轻飘飘的，女孩子家用的玩意。");
                set("value", 2000);
                set("material", "iron");
                set("wield_msg", "$N「唰」地拔出一把$n，握在手中。\n");
                set("unwield_msg", "$N「哧」地将$n插回了剑鞘中。\n");
        }

        init_sword(20);
        setup();
}
