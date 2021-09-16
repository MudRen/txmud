// xue.c 漫天风雪
// feixue-liantian 的特攻

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
                return notify_fail("『飞雪连天』只能对战斗中的对手使用。\n");

        if( ( skill = (int)me->query_skill("feixue-liantian",1)) < 100)
                return notify_fail("你对『飞雪连天』认识不够，无法使用“漫天风雪”。\n");
  
        if( (int)me->query("force")< 200 )
                return notify_fail("你的内力不够，无法使用“漫天风雪”。\n");

        msg = HIY+"$N使出一招「漫天风雪」，数十枚%s兵分两路，一路射向$n前胸，另一路飞到$n身后回头击向其后心。\n"+NOR;
        message_vision(msg, me, target);

        me->start_busy(1);
        me->add("force", -200);

        if( (random(me->query("combat_exp")/30)*random(skill)) > ((int)target->query("combat_exp")/2) )
        {
                msg =HIR "$N被攻击的手足无措，数之不清的%s打入$N周身！\n" NOR;

                damage =40+random((int)me->query("str") * (int)me->query_skill("force") /10)/3;

                message_vision(msg,target);

                target->receive_damage("kee",damage,me);

                COMBAT_D->report_status(target);
                return 1;
                return 1; 

        }

        else
                msg = "$n向前一冲，向左侧一让，就地一滚，堪堪躲开所有的暗器。\n" NOR;

        message_vision(msg, me, target);
        me->start_perform_busy(15);
        return 1;
}
