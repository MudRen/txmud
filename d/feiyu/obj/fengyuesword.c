// fengyuesword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
	set_name(HIW"风月剑"NOR, ({ "fengyue sword","sword" }) );
	set_weight(800);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long", "这是一把武林中人人都梦想得到的宝剑.\n");
		set("value", 40000);
		set("material", "steel");
		set("valid_number",1);

		set("wield_msg", "$N从剑鞘里抽出一把雪白的$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘中。\n");

		set("wield_skill",([
			"sword" : 150,
		]));
		set("wield_ability",([
			"combat_exp" : 600000,
		]));
	}

	init_sword(80);
	setup();
}
