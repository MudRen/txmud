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
              return notify_fail(HIY"牵制攻击只能对战斗中的对手使用。\n"NOR);

       if( target->is_busy() )
              return notify_fail(target->name() + HIY"目前正自顾不暇，放胆攻击吧！\n"NOR);

       msg = HIB "$N使出「缠丝擒拿手」的“缠”字诀，化作无数个圆圈缠向$n的全身。\n"NOR;
       
       me->start_busy(1);
       
       if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
              msg += HIY"结果$p被$P的招数弄的险象环生，狼狈之极！\n" NOR;
              target->start_busy( (int)me->query_skill("chansi-shou") / 20 + 2);

       } else {
              msg += HIY"虽然$p堪堪躲开了$P的招数，但也惊出了一身冷汗。\n" NOR;
              me->start_busy(2);
       }
       message_vision(msg, me, target);

       return 1;
}
