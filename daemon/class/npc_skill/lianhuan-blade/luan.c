// luan.c
// ������

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int extra,msen;
	object weapon;

	if(me->is_busy())
		return 0;

	extra = me->query_skill("lianhuan-blade",1);
	if ( extra < 50)
		return notify_fail("��������������������죡\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query("force")<=100)
		return notify_fail("����������㣬�޷�ʹ�ý�����\n");

	if(!objectp(weapon = me->query_temp("weapon")))
		return 0;

        me->add("force",-100);
        me->start_busy(2);

	message_vision(sprintf(HIY "$N���һ��������%s���һ����������Ȼʹ���������衹��\n" NOR,weapon->name()),me,target);

	msen = target->query("max_sen")/20;
	message_vision(HIY "��һ��......\n" NOR,me,target);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	target->receive_wound("sen", msen, me);
	message_vision(HIY "��һ��......\n" NOR,me,target);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	target->receive_wound("sen", msen, me);
	message_vision(HIY "��һ��......\n" NOR,me,target);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	target->receive_wound("sen", msen, me);
	message_vision(HIY "��һ��......\n" NOR,me,target);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	target->receive_wound("sen", msen, me);
	message_vision(HIY "�м�����һ��......\n" NOR,me,target);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	target->receive_wound("sen", msen, me);

	return 1;
}
