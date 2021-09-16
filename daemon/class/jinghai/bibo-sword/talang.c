// talang.c
// bibo-sword ���ع�

#include <ansi.h>

#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int extra, rir, force;

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	extra = me->query_skill("bibo-sword",1);

	if ( extra < 60)
		return notify_fail("��ġ��̲����������������죡\n");

	if( !target )
		target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
                return notify_fail("���̲�̤�ˡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (force = me->query("force")) <= 100 )
		return notify_fail("����������㣬�޷�ʹ�á��̲�̤�ˡ���\n");

	rir = target->query_skill("dodge",1);

	message_vision(HIG"$Nʹ�����̲�������֮����֮�ء��̲�̤�ˡ���\n"NOR,me);

	if(random(me->query("combat_exp")*(extra/10+1))>target->query("combat_exp")*(rir/30+1))
	{
		int n,i;

		message_vision(HIG "$Nһ����Х�����γ������������һ������ʹ�������̳�����,���ֻ��˸���Բ��ס���ţ�\n" NOR,me,target);

		if(extra > 250)
			n = 5;
		else if(extra > 200)
			n = 4;
		else if(extra > 120)
			n = 3;
		else
			n = 2;

		if(force < (n*100))
			n = to_int(force/100);

		for(i=0;i<n;i++)
			COMBAT_D->do_attack(me,target,TYPE_QUICK);

		message_vision(sprintf(HIC "\n$N���˾�����Ȼ����%s��,$n���������˸���æ���ң�\n\n" NOR,
			chinese_number(n)),me,target);

		n--;
		me->add("force",-n*100);
		me->receive_damage("sen",n*10,"tire");
	}

	else
	{
		message_vision("\n��$n����$N����ͼ�����Ʒ���������\n\n",me,target);
		COMBAT_D->do_attack(target,me,TYPE_QUICK);
		me->add("force",-100);
	}

	target->start_busy(1);
	me->start_busy(1);
	me->start_perform_busy(8);
	return 1;
}
