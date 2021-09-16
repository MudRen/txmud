// tan.c
// 飞龙探海

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int extra, msen;
	object weapon;

	if(me->is_busy())
		return 0;

	extra = me->query_skill("feilong-quan",1);
	if ( extra < 50)
		return notify_fail("你的飞龙服虎拳还不够纯熟！\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("飞龙服虎拳只能对战斗中的对手使用。\n");

        if (me->query("force")<=100)
		return notify_fail("你的内力不足，无法使用飞龙探海\n");

	if(objectp(weapon = me->query_temp("weapon")))
		return 0;

        me->add("force",-100);
        me->start_busy(1);
	msen = target->query("max_sen")/20;

	message_vision(HIY "\n$N大吼一声，使出飞龙服虎拳的绝招「飞龙探海」！\n" NOR,me,target);
	if( random(me->query("combat_exp")/30*extra) > (int)target->query("combat_exp")*7/2 ) 
	{
		for(int i=0;i<4;i++)
		{
			COMBAT_D->do_attack(me,target,TYPE_QUICK);
			target->receive_wound("sen", msen, me);
		}
		return 1;

	}

	else
		message_vision("$n向后一纵躲开这招，但也吓出了一身冷汗。\n" NOR, me, target);
	return 1;
}
