// chan.c

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
       string msg;

       if( !target ) target = offensive_target(me);

       if( !target
       ||     !target->is_character()
       ||     !me->is_fighting(target) )
              return notify_fail(HIY"ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

       if( target->is_busy() )
              return notify_fail(target->name() + HIY"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n"NOR);

       msg = HIB "$Nʹ������˿�����֡��ġ������־�������������ԲȦ����$n��ȫ��\n"NOR;
       
       me->start_busy(1);
       
       if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
              msg += HIY"���$p��$P������Ū�����������Ǳ�֮����\n" NOR;
              target->start_busy( (int)me->query_skill("chansi-shou") / 20 + 2);

       } else {
              msg += HIY"��Ȼ$p�����㿪��$P����������Ҳ������һ���亹��\n" NOR;
              me->start_busy(2);
       }
       message_vision(msg, me, target);

       return 1;
}
