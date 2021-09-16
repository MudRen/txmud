//hunt-fork.c 猎叉
#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name("猎叉", ({ "hunter fork","fork","hf" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "这是一杆细长的猎叉，足有一丈来长。\n");
                set("value", 4000);
                set("material", "iron");
                set("wield_msg", "$N将$n紧紧攥在手里，紧张的看着四周。\n");
                set("unwield_msg", "$N松开了手中的$n。\n");
        }
        init_fork(30);
        setup();
}

