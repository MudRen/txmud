#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
    set_name(HIW "菜刀", ({ "sword" }) );
    set_weight(0);
    if(clonep() )
        set_default_object(__FILE__);
    else
    {
    set("unit", "柄");
    set("long", "一把奇特的刀，因为它没有刀刃，只有刀把。");
    set("value", 99);
    set("material", "iron");
    set("wield_msg", "$N“嘿嘿”一笑，挥舞出一把$n！\n");
    set("unwield_msg", "$N把$n收起来，省得弄坏了。\n");
    }

    init_sword(320);
    setup();
}
