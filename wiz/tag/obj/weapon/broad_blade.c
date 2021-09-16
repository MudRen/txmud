#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("宽刃砍刀", ({ "broad blade" }) );
        set_weight(8000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "柄");
                set("long", "这是一柄宽刃砍刀，刀身很大，分量也比一般刀重。\n");
                set("value", 5000);
                set("material", "iron");
                set("wield_msg", "$N「呼」地一下挥出一柄$n，双手紧紧握住刀把。\n");
                set("unwield_msg", "$N松开了手中的$n。\n");
        }

        init_blade(40);
        setup();
}
