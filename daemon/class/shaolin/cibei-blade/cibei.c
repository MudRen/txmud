// cibei.c
// �ҷ�ȱ� cibei
// �ȱ���(cibei-blade)���ع�

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,my_force,ap,dp;
	object weapon;

	if(me->is_busy())
		return notify_fail("����һ������û����ɣ��޷�ʹ�á��ҷ�ȱ�����\n");

	if((skill = me->query_skill("cibei-blade",1)) < 100)
		return notify_fail("��ȱ������������죬�޷�ʹ�á��ҷ�ȱ�����\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("���ҷ�ȱ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	my_force = me->query("force");

	if(skill >= 250)
	{
		num = 12; force = 500;
	}

	else if(skill >= 170)
	{
		num = 7; force = 350;
	}

	else
	{
		num = 4; force = 150;
	}

	if(my_force < force)
		return notify_fail("��Ŀǰ���������㣬�޷�ʩչ���ҷ�ȱ���\n");

	if(!weapon = me->query_temp("weapon"))	// stick ��˫�ֱ�����
		return notify_fail("���޷�ʩչ���ҷ�ȱ���\n");

	me->add("force",-force);

	message_vision(sprintf(HIC"\n$N����һ����ţ�����%sһȦ���ó�һƬ�������$n��\n"NOR,weapon->name()),me,target);
	ap = COMBAT_D->skill_power(me,"blade",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE);
	if(random(ap + dp) < dp)
		num = 1;
	if(target->query("can_speak"))
		message_vision(sprintf(HIY"\n$N��$n�������壬������һ��%s\n"NOR,
			num == 1?"��":"������ɬ��������㯵�����ǰ����\n"),target,me);
	target->start_busy(num);
	me->start_busy(1);

	// start_perform_busy() Ϊʹ�� perform �ļ������λΪ��������
	// ÿ�� perform �����д����ã�����perform �ǲ�������ʹ�õġ�
	me->start_perform_busy(15);
	return 1;
}
