// fw_gun.c

#include <weapon.h>

inherit STICK;

void create()
{
	set_name("水火大棍", ({ "shuihuo gun", "gun" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "根");
		set("long", "这是一根官府衙役用的水火大棍。");
		set("value", 300);
		set("material", "wood");
		set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}

	init_stick(20);
	setup();
}