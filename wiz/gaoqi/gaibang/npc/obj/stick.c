// fw_gun.c

#include <weapon.h>

inherit SWORD;
void create()
{
   set_name("神木棒", ({ "shenmu bang", "bang" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
        set("unit", "把");
        set("long", "这是一把用檀香木做的剑。");
        set("value", 99);
		set("material", "wood");
        set("wield_msg", "$N缓缓地拔出一把$n!\n");
        set("unwield_msg", "$N收起手中的$n。\n");
	}

    init_sword(320);
	setup();
}
