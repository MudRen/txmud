// xiangmo.c
// 韦陀降魔 xiangmo
// 韦陀棍(weituo-gun)的特攻

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,my_force;
	object weapon;

	if(me->is_busy())
		return notify_fail("你上一个动作没有完成，无法使用『韦陀降魔』。\n");

	if((skill = me->query_skill("weituo-gun",1)) < 100)
		return notify_fail("你韦陀棍法不够纯熟，无法使用『韦陀降魔』。\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("『韦陀降魔』只能对战斗中的对手使用。\n");

	my_force = me->query("force");

	if(skill >= 250)
	{
		num = 5; force = 500;
	}

	else if(skill >= 170)
	{
		num = 4; force = 350;
	}

	else
	{
		num = 3; force = 150;
	}

	if(my_force < force)
		return notify_fail("你目前的内力不足，无法施展『韦陀降魔』");

	if(!weapon = me->query_temp("weapon"))	// stick 是双手兵器。
		return notify_fail("你无法施展『韦陀降魔』");

	me->add("force",-force);

	message_vision(sprintf(HIC"\n$N大吼一声，力贯%s，施展出少林绝技%s。\n\
手中%s劈头盖脸地向$n砸去！！\n"NOR,weapon->name(),HIB+"『韦陀降魔』"+HIC,
weapon->name()),me,target);
	for(int i=1;i<=num;i++)
	{
		COMBAT_D->do_attack(me,target,TYPE_QUICK);
	}

	if(target->query("can_speak"))
		message_vision(HIC"\n$N被$n的神威所慑，不觉得一呆。\n"NOR,target,me);
	target->start_busy(1);
	me->start_busy(1);

	// start_perform_busy() 为使用 perform 的间隔，单位为心跳数。
	// 每个 perform 必须由此设置，即：perform 是不能连续使用的。
	me->start_perform_busy(8);
	return 1;
}