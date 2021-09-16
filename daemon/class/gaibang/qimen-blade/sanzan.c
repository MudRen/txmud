// sanzan
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����ң��ն��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("qimen-blade", 1) < 100 )
		return notify_fail("������ŵ���������죬�޷�ʹ�á���ң��ն����\n");
	if( (int)me->query_skill("gaibang-force", 1) < 80 )
		return notify_fail("���ؤ���ķ������ߡ�\n");

	if((int)me->query("max_force",1)< 600)
		return notify_fail("���������Ϊ�������޷�ʹ�á���ң��ն����\n");

	if( (int)me->query("force", 1) < 400 )
		return notify_fail("����������̫��������ʹ�á���ң��ն����\n");

	msg = CYN "$N��ɫ���䣬����Ʈ�����������󼲶���ǧ�������������Ʈѩ������ǵط���$n��\n\n"NOR;
	if(random(me->query("combat_exp")) > target->query("combat_exp")/3 )
	{
	msg += HIR"ֻ��$N��̤����ˣ���ң��ն���Ϊһ�ߣ�����$n,\n$n" HIR "ֻ��һ�����������������������������������Ѫ���������\n\n"NOR;

	damage = (int)me->query_skill("gaibang-force", 1);
	damage = damage +  (int)me->query_skill("qimen-blade", 1);
	damage=damage/3+random(damage);
	target->receive_damage("kee", damage);
	target->receive_wound("kee", random(damage/3));
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	me->add("force", -damage);
	}
	else 
	{
	msg += CYN"����$p���з�����Ц�������������ŵ����ڰ�����ң��ն���ѵ����κε����ң�\n\n"NOR;
	me->add("force", -200);
	me->start_busy(1);
	}
	message_vision(msg, me, target);
	me->start_perform_busy(8);
	return 1;
}
