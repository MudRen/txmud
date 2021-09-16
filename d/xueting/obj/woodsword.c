// liuyun-sword.c
// edit by pian

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
	set_name( HIW"木剑" NOR, ({ "wood sword" }) );
	set_weight(6000);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
一把硬木雕成的剑，剑身上有古朴的花纹，但已经被烟火熏的乌七麻黑的了。
LONG
);

		set("valid_number",3);
		set("value", 300);
		set("material", "wood");
		set("wield_msg", HIW"$N「刷」地一声抽出一柄乌七麻黑的$n"+HIW"握在手中。\n"NOR);
		set("unwield_msg", HIW"$N将手中的$n"+HIW"收入腰间。\n"NOR);
//		set("weapon_prop/courage", 10);
//		set("weapon_prop/intelligence", 10);
//		set("weapon_prop/personality", 10);
	
		// 装备此兵器需要玩家的武功 sword >5 ,parry >5.
		set("wield_skill",([
		"sword" : 5,
		"parry" : 5,
	]));
	
	        /* 装备此兵器需要内力上限大于 50,经验大于五万.
		set("wield_ability",([
		"max_force" : 300,
		"combat_exp" : 50000,
	]));
	*/
}
        init_sword(5);
        setup();
}
