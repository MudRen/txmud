// sword.c
// by dicky

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIW"长剑"NOR, ({"sword"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long", "这是一把看起相当普通的长剑，上面刻有〖踏雪山庄〗的标记。\n");
		set("value", 10);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}

	init_sword(35);
	setup();
}