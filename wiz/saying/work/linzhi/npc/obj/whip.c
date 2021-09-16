#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("长鞭", ({ "whip" }) );
        set_weight(4000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "条");
                set("long", "这是一条长鞭，足有九尺多长。");
                set("value", 3000);
                set("material", "iron");
                set("wield_msg", "$N摸出一条$n，紧握手中。\n");
                set("unwield_msg", "$N将$n盘了几盘，小心地收在腰间。\n");
        }

        init_whip(25);
        setup();
}

