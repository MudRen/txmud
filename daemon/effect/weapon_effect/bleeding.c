// bleeding.c

#include <mangle.h>

protected int weapon_bad;

protected void create()
{
	weapon_bad = W_MAX_MANGLE*3/4;
}

mixed weapon_effect(object me, object victim, int wound)
{
	object ob = query_shadowing();
	int bleed, n;

	if(!ob || !me || !victim
	|| !ob->is_weapon()
	|| (ob->query("mangle") >= weapon_bad) )
		return;

	n = ob->query("weapon_prop/damage");
	bleed = n/10 + 2;
	if(bleed > 10)
		bleed = 10;

	me->apply_condition("weapon_bleeding", bleed);
	return 0;
}
