#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIR"杀手之剑"NOR, ({ "killer sword","sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("unit", "把");
		set("long", "杀手之剑是绯雨阁弟子暗杀专用的利器。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N从剑鞘里抽出一把鲜红的$n握在手中，顿是周围杀气四起。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘中。\n");

		set("wield_skill",([
			"sword" : 150,
		]));
		set("wield_ability",([
			"combat_exp" : 500000,
		]));
	}
        init_sword(70);

        setup();
}

