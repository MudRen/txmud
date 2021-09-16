// fw_gun.c

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("绯雨权杖", ({ "feiyu quanzhang", "zhang" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
       set("unit", "根");
       set("long", "这是绯雨阁象征权力的法杖，据说它法力无穷。");
        set("value", 99);
		set("material", "wood");
        set("wield_msg", "$N缓缓地拔出一把$n!\n");
        set("unwield_msg", "$N收起手中的$n。\n");
	}

    init_sword(320);
	setup();
}
