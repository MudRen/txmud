// longquan_sword.c :

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("龙泉宝剑", ({ "longquan sword" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long", "这是一把寒光闪闪的龙泉宝剑。\n");
		set("value", 4000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}

	init_sword(40);
	setup();
}
