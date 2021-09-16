// xiangmo.c
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	if(!target) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�콫��ħֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("feitian-zhang", 1) < 100 )
		return notify_fail("��ķ����ȷ�������죬����ʹ�á��콫��ħ����\n");
	if( (int)me->query_skill("gaibang-force", 1) < 100 )
		return notify_fail("���ؤ���ķ������ߣ�����ʹ�÷����˵С�\n");

	if( (int)me->query("max_force", 1) < 600 )
		return notify_fail("���������Ϊ����������ʹ�á��콫��ħ����\n");

	if ((int)me->query("force",1) < 400)
		return notify_fail("��������������޷�ʹ�÷��ȡ�\n");

	if( (int)me->query_str() < 30 )
		return notify_fail("��������������������ȡ�\n");

	msg = HIW"\n$NͻȻ��"+weapon->name()+HIW"�����֣�����һ������"+weapon->query("name")+ HIW "�������$n��\n\n"NOR;

	if(random(me->query("combat_exp")) > target->query("combat_exp")/3)
	{
	msg += HIR"$n" HIR "�ͼ����һ������æ�����ܣ���ֻ��һ�ɴ�������ǵذ�ѹ����\n��ʱ��ǰһ������������,�۵����һ����Ѫ����\n\n"NOR;

	damage = (int)me->query_skill("fengmo-zhang", 1);
	damage = damage +  (int)me->query_skill("staff", 1);
	damage=damage/3+random(damage);
	target->receive_damage("kee", damage);
	target->receive_wound("kee", random(damage/3));
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	me->add("force", -damage);
	target->start_busy(1);
	}
	else 
	{
	msg += HIW"����$p���²���͵���ǰһԾ,������$P�Ĺ�����Χ��\n\n"NOR;
	me->add("force", -200);
	me->start_busy(1);
	}
	message_vision(msg, me, target);
	me->start_perform_busy(8);
	return 1;
}
