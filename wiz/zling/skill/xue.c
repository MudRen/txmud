// xue.c �����ѩ
// feixue-liantian ���ع�

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int skill, damage;

        if( !target )
                target = offensive_target(me);

        if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("����ѩ���졻ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( ( skill = (int)me->query_skill("feixue-liantian",1)) < 100)
                return notify_fail("��ԡ���ѩ���졻��ʶ�������޷�ʹ�á������ѩ����\n");
  
        if( (int)me->query("force")< 200 )
                return notify_fail("��������������޷�ʹ�á������ѩ����\n");

        msg = HIY+"$Nʹ��һ�С������ѩ������ʮö%s������·��һ·����$nǰ�أ���һ·�ɵ�$n����ͷ��������ġ�\n"+NOR;
        message_vision(msg, me, target);

        me->start_busy(1);
        me->add("force", -200);

        if( (random(me->query("combat_exp")/30)*random(skill)) > ((int)target->query("combat_exp")/2) )
        {
                msg =HIR "$N�������������޴룬��֮�����%s����$N����\n" NOR;

                damage =40+random((int)me->query("str") * (int)me->query_skill("force") /10)/3;

                message_vision(msg,target);

                target->receive_damage("kee",damage,me);

                COMBAT_D->report_status(target);
                return 1;
                return 1; 

        }

        else
                msg = "$n��ǰһ�壬�����һ�ã��͵�һ���������㿪���еİ�����\n" NOR;

        message_vision(msg, me, target);
        me->start_perform_busy(15);
        return 1;
}
