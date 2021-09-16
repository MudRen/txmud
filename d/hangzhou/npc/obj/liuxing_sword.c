// liuxing_sword.c

#include <weapon.h>

inherit SWORD;
inherit F_CONTROL;

void create()
{
	set_name("流星赶月剑", ({ "liu xing sword" }) );
	set_weight(10000);
	set("valid_number",10); // 10把

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long", "这是一把寒气逼人宝剑，看起不是一件凡品。\n");
		set("value", 50000);
		set("material", "steel");
		set("weapon_prop/courage", 30);

		set("wield_skill",([
			"sword" : 100,
		]));

		set("wield_ability",([
			"max_force" : 100,
			"combat_exp" : 100000,
                ]));

		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}

	init_sword(60);
	setup();
}