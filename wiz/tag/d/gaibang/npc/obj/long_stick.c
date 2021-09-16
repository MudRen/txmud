#include <weapon.h>
#include <ansi.h>
inherit STICK;

void create()
{
    set_name("长棍", ({ "long stick" }) );
    set_weight(3000);
    if(clonep() )
        set_default_object(__FILE__);
    else
    {
    set("unit", "根");
    set("long", "这根木头棍子足有一丈多长。");
    set("value", 1000);
    set("material", "wood");
    set("wield_msg", "$N双手紧紧握住了$n。\n");
    set("unwield_msg", "$N手松开了$n。\n");
    }

    init_stick(20);
    setup();
}

