// xiangmo.c
// Τ�ӽ�ħ xiangmo
// Τ�ӹ�(weituo-gun)���ع�

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,my_force;
	object weapon;

	if(me->is_busy())
		return notify_fail("����һ������û����ɣ��޷�ʹ�á�Τ�ӽ�ħ����\n");

	if((skill = me->query_skill("weituo-gun",1)) < 100)
		return notify_fail("��Τ�ӹ����������죬�޷�ʹ�á�Τ�ӽ�ħ����\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("��Τ�ӽ�ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

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
		return notify_fail("��Ŀǰ���������㣬�޷�ʩչ��Τ�ӽ�ħ��");

	if(!weapon = me->query_temp("weapon"))	// stick ��˫�ֱ�����
		return notify_fail("���޷�ʩչ��Τ�ӽ�ħ��");

	me->add("force",-force);

	message_vision(sprintf(HIC"\n$N���һ��������%s��ʩչ�����־���%s��\n\
����%s��ͷ��������$n��ȥ����\n"NOR,weapon->name(),HIB+"��Τ�ӽ�ħ��"+HIC,
weapon->name()),me,target);
	for(int i=1;i<=num;i++)
	{
		COMBAT_D->do_attack(me,target,TYPE_QUICK);
	}

	if(target->query("can_speak"))
		message_vision(HIC"\n$N��$n���������壬������һ����\n"NOR,target,me);
	target->start_busy(1);
	me->start_busy(1);

	// start_perform_busy() Ϊʹ�� perform �ļ������λΪ��������
	// ÿ�� perform �����ɴ����ã�����perform �ǲ�������ʹ�õġ�
	me->start_perform_busy(8);
	return 1;
}