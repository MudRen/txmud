// sword.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIG"华山长剑"NOR, ({ "huashan sword" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把看起相当轻盈的长剑，份量大约有七八斤。\n");
		set("value", 4000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
}

	init_sword(40);

	setup();
}
