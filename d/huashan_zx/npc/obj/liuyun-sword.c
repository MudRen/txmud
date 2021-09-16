// liuyun-sword.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
	set_name( WHT"流云剑" NOR, ({ "liuyun sword" }) );
	set_weight(6000);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
流云剑是华山剑宗大师风清杨年青时成名的兵器。
剑长二尺七寸，宽一寸九分，穗长一尺一寸，极北寒铁
所铸。此剑传说不仅是削铁如泥的利器，在云雨天使用
还能有一些不为人能的功效。
LONG
);

		set("valid_number",1);
		set("value", 30000);
		set("material", "steel");
		set("wield_msg", WHT"$N「刷」地一声抽出一柄闪著寒光的$n握在手中。\n"NOR);
		set("unequip_msg", WHT"$N将手中的$n插入腰间的剑鞘。\n"NOR);
		set("weapon_prop/courage", 10);
		set("weapon_prop/intelligence", 10);
		set("weapon_prop/personality", 10);
	
		// 装备此兵器需要玩家的武功 sword >50 ,parry >50.
		set("wield_skill",([
		"sword" : 50,
		"parry" : 50,
	]));
	
	        // 装备此兵器需要内力上限大于 300,经验大于五万.
		set("wield_ability",([
		"max_force" : 300,
		"combat_exp" : 50000,
	]));
}
        init_sword(60);
        setup();
}
