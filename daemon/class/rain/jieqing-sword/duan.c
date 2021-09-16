// duan.c
// ������� duan
// ���齣��(jieqing-sword)���ع�

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,my_force;
	object weapon;

	if(me->is_busy())
		return notify_fail("����һ������û����ɣ��޷�ʹ�á�������塻��\n");

	if((skill = me->query_skill("jieqing-sword",1)) < 150)
		return notify_fail("��Ľ��齣���������죬�޷�ʹ�á�������塻��\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("��������塻ֻ�ܶ�ս���еĶ���ʹ�á�\n");

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
		return notify_fail("��Ŀǰ���������㣬�޷�ʩչ��������塻");

	me->add("force",-force);

	if(!weapon = me->query_temp("weapon"))
		return notify_fail("���޷�ʩչ��������塻\n");

	message_vision(sprintf("\n$Nһ����߳��ʩչ\x1B[1;31m\x1B[47m��������塻\x1B[2;37;0m
����%sѸ���ޱȵ���$n�̳�%s����\n\n",weapon->name(),chinese_number(num)),me,target);

	for(int i=1;i<=num;i++)
	{
		COMBAT_D->do_attack(me,target,TYPE_QUICK);
	}

	//target->start_busy(1);
	me->start_busy(1);

	// start_perform_busy() Ϊʹ�� perform �ļ������λΪ��������
	// ÿ�� perform �����ɴ����ã�����perform �ǲ�������ʹ�õġ�
	me->start_perform_busy(10);
	return 1;
}
