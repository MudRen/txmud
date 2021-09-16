// duan.c
// 断情绝义 duan
// 戒情剑法(jieqing-sword)的特攻

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,my_force;
	object weapon;

	if(me->is_busy())
		return notify_fail("你上一个动作没有完成，无法使用『断情绝义』。\n");

	if((skill = me->query_skill("jieqing-sword",1)) < 150)
		return notify_fail("你的戒情剑法不够纯熟，无法使用『断情绝义』。\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("『断情绝义』只能对战斗中的对手使用。\n");

	my_force = me->query("force");

	if(skill >= 250)
	{
		num = 4; force = 280;
	}

	else if(skill >= 200)
	{
		num = 3; force = 210;
	}

	else
	{
		num = 2; force = 150;
	}

	if(my_force < force)
		return notify_fail("你目前的内力不足，无法施展『断情绝义』");

	me->add("force",-force);

	if(!weapon = me->query_temp("weapon"))
		return notify_fail("你无法施展『断情绝义』\n");

	message_vision(sprintf("\n$N一声娇叱，施展\x1B[1;31m\x1B[47m『断情绝义』\x1B[2;37;0m
手中%s迅捷无比地向$n刺出%s剑！\n\n",weapon->name(),chinese_number(num)),me,target);

	for(int i=1;i<=num;i++)
	{
		COMBAT_D->do_attack(me,target,TYPE_QUICK);
	}

	//target->start_busy(1);
	me->start_busy(1);

	// start_perform_busy() 为使用 perform 的间隔，单位为心跳数。
	// 每个 perform 必须由此设置，即：perform 是不能连续使用的。
	me->start_perform_busy(10);
	return 1;
}
