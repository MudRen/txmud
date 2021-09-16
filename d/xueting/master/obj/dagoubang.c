// dagoubang.c
// edit by pian

#include <ansi.h>
#include <weapon.h>
inherit STAFF;
inherit F_CONTROL;

void create()
{
	set_name( HIY"翠竹杖" NOR, ({ "dagoubang" }) );
	set_weight(6000);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
翠竹杖是丐帮帮主代代相传的信物，质地奇异，非金非
玉，通体碧绿；长三尺七寸，穗长一尺一寸有节、有眼、
挥动其声若磬。此杖传说中刀剑不能断，水火不能侵。
在云雨天使用还能有一些不为人能的功效。
LONG
);

		set("valid_number",1);
		set("value", 9000);
		set("material", "blacksteel");
		set("wield_msg", HIR"$N「刷」地一声抽出一根闪著碧绿光泽的$n"+HIR"握在手中。\n"NOR);
		set("unequip_msg", HIR"$N将手中的$n"+HIR"收入怀中。\n"NOR);
		set("weapon_prop/courage", 10);
		set("weapon_prop/intelligence", 10);
		set("weapon_prop/personality", 10);
	
		// 装备此兵器需要玩家的武功 sword >90 ,parry >90.
		set("wield_skill",([
		"staff" : 90,
		"parry" : 90,
	]));
	
	        // 装备此兵器需要内力上限大于 300,经验大于五万.
		set("wield_ability",([
		"max_force" : 1000,
		"combat_exp" : 500000,
	]));
}
        init_staff(90);
        setup();
}
