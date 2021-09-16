// damo.c
// ��Ħ��ʽ damo
// ��Ħ��(damo-sword)���ع�

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,my_force;
	object weapon;

	if(me->is_busy())
		return notify_fail("����һ������û����ɣ��޷�ʹ�á���Ħ��ʽ����\n");

	if((skill = me->query_skill("damo-sword",1)) < 100)
		return notify_fail("��Ĵ�Ħ�����������죬�޷�ʹ�á���Ħ��ʽ����\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("����Ħ��ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

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
		return notify_fail("��Ŀǰ���������㣬�޷�ʩչ����Ħ��ʽ��");

	me->add("force",-force);

	if(!weapon = me->query_temp("weapon"))
		return notify_fail("���޷�ʩչ����Ħ��ʽ��\n");

	message_vision(sprintf(HIC"\n$N���һ��������%s��â���ǣ�ʩչ�����־�ѧ%s��\n
������$n���˹�ȥ����\n"NOR,weapon->name(),HIW BWHT+"����Ħ��ʽ��" NOR+HIC),me,target);
	for(int i=1;i<=num;i++)
	{
		COMBAT_D->do_attack(me,target,TYPE_QUICK);
	}

	if(target->query("can_speak"))
		message_vision(HIC"\n$N��$n���������壬������һ����\n"NOR,target,me);
	target->start_busy(1);
	me->start_busy(2);

	// start_perform_busy() Ϊʹ�� perform �ļ������λΪ��������
	// ÿ�� perform �����ɴ����ã�����perform �ǲ�������ʹ�õġ�
	me->start_perform_busy(15);
	return 1;
}
