#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("巨铁锤", ({ "huge hammer" }) );
        set_weight(20000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "把");
                set("long", "这把巨大的铁锤足有二十斤重。\n");
                set("value", 8000);
                set("material", "iron");
                set("wield_msg", "$N大喝一声，双手紧紧握住了$n。\n");
                set("unwield_msg", "$N松开了手中的$n。\n");
        }

        init_hammer(40);
        setup();
}

