// ziyansword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
        set_name(HIM"紫烟剑"NOR, ({ "ziyan sword","sword" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("long", "这是一把长约二尺八寸，剑身隐隐透出紫色霞气的锋利宝剑。\n");
		set("value", 200000);
		set("material", "steel");
		set("wield_skill",([
			"sword" : 200,
		]));
		set("wield_ability",([
			"combat_exp" : 500000,
		]));
	}

        init_sword(80);
        setup();
}
