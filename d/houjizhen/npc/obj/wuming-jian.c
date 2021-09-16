// wuming-jian.c
// by dicky

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
        set_name(HIR"无名宝剑"NOR, ({ "wuming baojian", "wuming", "sword", "jian"}) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 10);
                set("rigidity", 5);
                set("sharpness", 3);
                set("material", "steel");
                set("weapon_prop/dodge", 2);
                set("treasure",1);
                set("wield_str", 25);
                set("wield_msg", "只见寒光一闪，$N从身后抽出一把寒气森森的宝剑。\n");
                set("long", "此剑长约四尺，青光闪闪，是把削金断铁的利器\n");                
                set("unwield_msg","$N将无名宝剑小心的插回身后。\n");               
        }
        init_sword(45);
        setup();
}

