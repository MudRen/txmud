// po.c
// canhe-zhi ���ع�
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
                return notify_fail("���κ�ָ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( ( skill = (int)me->query_skill("canhe-zhi",1)) < 80)
		return notify_fail("��ġ��κ�ָ���������㣬�޷�ʹ�á��ơ��־���\n");

	if( (int)me->query("force")< 300 )
		return notify_fail("��������������޷�ʹ�á��ơ��־���\n");

	msg = HIR+"$N΢һ����, �����ζ�, ����ʳָ���. ��ָ�����һ�ɾ�������$n \n"+NOR;

	message_vision(msg, me, target);

	me->start_busy(1);
	me->add("force", -200);

	if( (random(me->query("combat_exp")/30)*random(skill)) > ((int)target->query("combat_exp")/2) )
	{
		msg =HIR "$N�������������޴룬ָ��ֱ͸$N����Ѩ��\n" NOR;

		damage =40+random((int)me->query("str") * (int)me->query_skill("force") /10)/3;

		message_vision(msg,target);

		target->receive_damage("kee",damage,me);

		COMBAT_D->report_status(target);
		return 1;

	}

	else
		msg = "$n���һ�ݶ㿪���У���Ҳ�ų���һ���亹��\n" NOR;

	message_vision(msg, me, target);
	me->start_perform_busy(15);
	return 1;
}
