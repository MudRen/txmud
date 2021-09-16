// po.c
// canhe-zhi 的特攻
// by mool

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int skill, damage;

	if( !target )
		target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
                return notify_fail("『参合指』只能对战斗中的对手使用。\n");

	if( ( skill = (int)me->query_skill("canhe-zhi",1)) < 80)
		return notify_fail("你的『参合指』功力不足，无法使用“破”字诀。\n");

	if( (int)me->query("force")< 300 )
		return notify_fail("你的内力不够，无法使用“破”字诀。\n");

	msg = HIR+"$N微一凝神, 气走任督, 左手食指轻扣. 中指点出，一股劲力射向$n \n"+NOR;

	message_vision(msg, me, target);

	me->start_busy(1);
	me->add("force", -200);

	if( (random(me->query("combat_exp")/30)*random(skill)) > ((int)target->query("combat_exp")/2) )
	{
		msg =HIR "$N被攻击的手足无措，指力直透$N丹田穴！\n" NOR;

		damage =40+random((int)me->query("str") * (int)me->query_skill("force") /10)/3;

		message_vision(msg,target);

		target->receive_damage("kee",damage,me);

		COMBAT_D->report_status(target);
		return 1;

	}

	else
		msg = "$n向后一纵躲开这招，但也吓出了一身冷汗。\n" NOR;

	message_vision(msg, me, target);
	me->start_perform_busy(15);
	return 1;
}
