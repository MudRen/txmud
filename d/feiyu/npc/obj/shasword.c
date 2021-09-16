#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"飞雪寒刃"NOR, ({ "feixue sword","sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把绯雨阁四杀手专门用的短剑。\n");
                set("value", 8000);
                set("material", "steel");
        }
        init_sword(40);

        set("wield_msg", "$N从剑鞘里抽出一把雪白的$n握在手中，顿是周围杀气四起。\n");
        set("unwield_msg", "$N将手中的$n插回剑鞘中。\n");

        setup();
}
