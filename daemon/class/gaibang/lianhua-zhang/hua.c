// hua.c
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�û������䣡\n");  
                
	if( (int)me->query_skill("lianhua-zhang", 1) < 100 )
		return notify_fail("��������Ʋ�����죬����ʹ�û������䣡\n");
                                
        if( (int)me->query_skill("gaibang-force", 1) < 100 )
                return notify_fail("���ؤ���ķ������ߣ������ó����������˵С�\n");

	if ( me->query_skill_mapped("unarmed") != "lianhua-zhang")
               return notify_fail("�������޷�ʹ�á��������䡹���й�����\n");                                                                                 
	if((int)me->query("max_force",1) < 600)
		return notify_fail("���������Ϊ�������޷�ʹ�á��������䡹��\n");

        if( (int)me->query("force") < 400 )
                return notify_fail("����������̫�����޷�ʹ���������䡣\n");

        msg = HIR"$N��ɫ���䣬����Ʈ�����������������дʣ��������������䡢���˸�����������......\n���ƻû�Ϊǧ�����Ӱ������Ʈѩ������ǵظ���$n��\n"NOR;

	if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
	{
	msg += HIR"\n���ֻ�����ԡ���һ����$n" HIR "��������޹���Ƶ���Х����Ѫ�ӿ��п��������\n\n"NOR;

	damage = (int)me->query_skill("gaibang-force", 1);
	damage = damage +  (int)me->query_skill("lianhua-zhang", 1);
	damage=damage/3+random(damage);
	target->receive_damage("kee", damage);
	target->receive_wound("kee", random(damage/3));
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	me->add("force", -damage);
	target->start_busy(1);
	}
	else 
	{
	msg += HIW"\n$n" HIW "ȫ������һ������������Ӱ��������������˵��������ޱȣ�\n\n" NOR;
	me->add("force", -200);
	me->start_busy(1);
	}
	message_vision(msg, me, target);
	me->start_perform_busy(8);
	return 1;
}