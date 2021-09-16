// zui.c
// ������ zui
// ����������(zuiyue-strike)���ع�

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,ap,dp,damage;
	string limb,*limbs;

	if(me->is_busy())
		return notify_fail("����һ������û����ɣ��޷�ʹ�á������᡻��\n");

	if((skill = me->query_skill("zuiyue-strike",1)) < 100)
		return notify_fail("�����������Ʋ������죬�޷�ʹ�á������᡻��\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("�������᡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	num = (skill - 100)/50 + 1;
	if(num > 5)
		num = 5;

	force = 100 + (num * 50);

	if(me->query("force") < force)
		return notify_fail("��Ŀǰ�������������޷�ʩչ�������᡻��\n");

	me->add("force",-force);
	me->start_busy(1);

	ap = COMBAT_D->skill_power(me,"unarmed",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE);

	if( !arrayp(limbs = target->query("limbs")) )
		return notify_fail("���ֲ�λ������֪ͨ��ʦ����\n");

	limb = limbs[random(sizeof(limbs))];

	message_vision(sprintf(BWHT HIB"\n$Nš������ʩչ�������ѧ�������᡻������\n����������Ϣ������$n��%s\n\n"NOR,
		limb),me,target);

	if(random(ap + dp) < dp) // ʧ��
	{
		message_vision("$nһ���������ܿ���$N����ʽ��\n\n",me,target);
		return 1;
	}

	damage = 50 + num*50;
	damage = damage/2 + random(damage/2);

	message_vision("$Nֻ����һ����ѣ�����۷�����\n\n",target);

	target->receive_damage("gin",damage,me);
	target->receive_damage("sen",damage,me);

	damage /= 5;

	target->receive_wound("gin",damage,me);
	target->receive_wound("sen",damage,me);

	COMBAT_D->report_status(target);

	// start_perform_busy() Ϊʹ�� perform �ļ������λΪ��������
	// ÿ�� perform �����д����ã�����perform �ǲ�������ʹ�õġ�
	me->start_perform_busy(12);
	return 1;
}
