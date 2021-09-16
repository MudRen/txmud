// sword:__DIR__"obj/guixin_sword.c" 归心剑一把

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("归心剑",({ "guixin sword","guixin","sword" }));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit", "柄");
                set("long", "这是一柄铁剑，因剑托形状向心而得名。\n");
                set("value", 600);
                set("material", "iron");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
         }
        init_sword(20);
        setup();
}
