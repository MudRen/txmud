// po.c
// ���ơ��־�
// ���½���(dugu-sword)���ع�   �����±���
// by dicky.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
 
int perform(object me, object target)
{
        string msg;
        object weapon, weapon2;
        int skill,damage;

//        target = me->select_opponent();

        skill = me->query_skill("dugu-sword",1);

	if( !target ) target = offensive_target(me);

        if( !target  || !target->is_character() || !me->is_fighting())
                return notify_fail("�����½������ġ��ơ��־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("�Է�û��ʹ�ñ��������޷�ʹ�á��ơ��־���\n");

        if( skill < 120)
                return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á��ơ��־���\n");

        if( me->query("force") < 500 )
                return notify_fail("��������������޷����á��ơ��־���\n");
 
        msg = HIC "\n$Nһ���Ϻȣ�ʹ�����¾Ž��ġ��ơ��־��ƽ�$n������"+weapon->name()+HIC "�ó����ؽ�Ӱ������˿����$n��ȥ��\n\n";
        message_vision(msg, me, target);
 
        damage = random(skill);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
        {
                if(userp(me))
                        me->add("force",-300);
                msg = "$n��ʱ����ѹ������������һ�飬����";
                msg += weapon2->name();
                msg += "���ֶ�����\n\n" NOR;

                target->receive_damage("kee", damage);
                target->start_busy(1);
                weapon2->move(environment(me));
        }
        else
        {
                if(userp(me))
                        me->add("force",-300);
                msg = "����$n������$N�Ľ�·�����̲�ȡ���ƣ�ʹ$N�ġ��ơ��־�û�����κ����á�\n"NOR;
                me->start_busy(1);
        }
        message_vision(msg, me, target);
	me->start_perform_busy(8);
        return 1;
}

