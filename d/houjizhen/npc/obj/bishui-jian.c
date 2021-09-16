// bishui-jian.c
// by dicky

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
        set_name(HIG "碧水剑" NOR, ({ "bishui jian", "jian", "sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是把又薄又轻的软剑，剑身上隐隐的透出白光，当真锋利无比。\n");
                set("value", 3000);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("material", "steel");
		set("valid_number",1);
                set("wield_str", 25);
                set("treasure",1);
                set("long","这是把又薄又轻的软剑，剑身上隐隐的透出绿光，当真锋利无比。\n");
                set("wield_msg", "只听见「嗡」地一声，白光顿现，$N将腰间解下的$n抖得笔直。\n");
                set("unequip_msg", "$N将手中的$n卷入腰间。\n");
        }
        init_sword(60);
        setup();
}
