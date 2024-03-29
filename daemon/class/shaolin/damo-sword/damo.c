// damo.c
// 达摩五式 damo
// 达摩剑(damo-sword)的特攻

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,my_force;
	object weapon;

	if(me->is_busy())
		return notify_fail("你上一个动作没有完成，无法使用『达摩五式』。\n");

	if((skill = me->query_skill("damo-sword",1)) < 100)
		return notify_fail("你的达摩剑法不够纯熟，无法使用『达摩五式』。\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("『达摩五式』只能对战斗中的对手使用。\n");

	my_force = me->query("force");

	if(skill >= 240)
	{
		num = 5; force = 500;
	}

	else if(skill >= 180)
	{
		num = 4; force = 350;
	}

	else
	{
		num = 3; force = 150;
	}

	if(my_force < force)
		return notify_fail("你目前的内力不足，无法施展『达摩五式』");

	me->add("force",-force);

	if(!weapon = me->query_temp("weapon"))
		return notify_fail("你无法施展『达摩五式』\n");

	message_vision(sprintf(HIC"\n$N大吼一声，手中%s剑芒暴涨，施展出少林绝学%s。\n
合身向$n扑了过去！！\n"NOR,weapon->name(),HIW BWHT+"『达摩五式』" NOR+HIC),me,target);
	for(int i=1;i<=num;i++)
	{
		COMBAT_D->do_attack(me,target,TYPE_QUICK);
	}

	if(target->query("can_speak"))
		message_vision(HIC"\n$N被$n的神威所慑，不觉得一呆。\n"NOR,target,me);
	target->start_busy(1);
	me->start_busy(2);

	// start_perform_busy() 为使用 perform 的间隔，单位为心跳数。
	// 每个 perform 必须由此设置，即：perform 是不能连续使用的。
	me->start_perform_busy(15);
	return 1;
}
