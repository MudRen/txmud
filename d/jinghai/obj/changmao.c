#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name( "长矛", ({ "chang mao","mao" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "枝");
                set("long", "一枝两丈多的长矛，矛头锋利。\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg", "$N拿起一枝$n，握在手中当作武器。\n");
                set("unwield_msg", "$N放下手中的$n。\n");                
        }

        init_fork(20);
        setup();
}

