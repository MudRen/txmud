//zang-blade.c 
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("藏刀", ({ "zang blade","blade","zb" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄明晃晃的藏刀，弯弯的刀身反射着寒光。\n");
                set("value",2500);
                set("material", "iron");
                set("wield_msg", "$N「唰」的一声从背后抽出一柄$n。\n");
                set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        }
        init_blade(30);
        setup();
}
