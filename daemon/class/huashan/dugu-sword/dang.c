// dang 荡剑式
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int tp;
        string msg;
        object weapon;
        
        if( !target ) target = offensive_target(me);    if( !me->query("dugu_pfm_dang") )
                return notify_fail("你还没有悟到独孤九剑的真髓，无法使出『荡剑式』。\n");

        if(!objectp(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!="sword")
          return notify_fail("『荡剑式』要有剑才能发出。\n");   

        if( !target     ||      !target->is_character() ||      !me->is_fighting(target) )              return notify_fail("『荡剑式』只能对战斗中的对手使用。\n");    if( target->is_busy() )         return notify_fail(target->name() + "目前正自顾不暇，不必再出『荡剑式』。\n");                      if( (int)me->query_skill("dugu-sword", 1) < 100 )           return notify_fail("你的独孤九剑不够娴熟，无法使出『荡剑式』。\n");    // 成功几率  
        // 1. kar 20, int 20  敌我exp差距从 敌3倍 到 我5倍
        //    成功率为从 1% 到 92%
        // 2. exp相同时 kar,int 从20 to 60
        //    成功率为从 51% 到 90%
        // 3. 都递增变化时成功率平均为 70% (exp相差十分悬殊除外)

        /*
        tp=0;
        for (i=0;i<1000;i++)
        {
    if ( (int)random(me->query("combat_exp",1)) > 
                 (int)target->query("combat_exp",1)/(((int)me->query("kar",1)+me->query("int",1)+1)/30+1.5) )
                 tp++;
        }
        printf("DEBUG: OK times of 1000 is %d \n",tp);
        */

        me->add("force",-random(200)-100 );

    if ( (int)random(me->query("combat_exp",1)) > 
                 (int)target->query("combat_exp",1)/(((int)me->query("kar",1)+me->query("int",1)+1)/30+1.5) )
        {       msg = HIG"\n$N"HIG"跃起腾空，手中的剑仿佛幻化无数光芒，向$n"HIG"发出了             "HIC;
        message_vision(msg, me, target);

msg="
∵∵∵∵∵∵◆∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵
∵∵∵∵∵∵■━━━━━━━━━━━━━∵∵∵∵∵∵∵∵∵∵∵

∵∵◆〓〓〓■━★━━━━━━━━━━━━＞∵∵『荡剑式』∵∵
∵∵∵∵∵∵■━━━━━━━━━━━━━∴∵∵∵∵∵∵∵∵∵∵
∵∵∵∵∵∵◆∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵◆∵∵∵∵∵∵
∵∵∵∵∵∵∵∵∵∵∵━━━━━━━━━━━━━■∵∵∵∵∵∵
∵∵『荡剑式』∵∵＜━━━━━━━━━━━━★━■〓〓〓◆∵∵
∵∵∵∵∵∵∵∵∵∵∴━━━━━━━━━━━━━■∵∵∵∵∵∵
∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵◆∵∵∵∵∵∵
"NOR;
     message_vision(msg, me, target);
                msg = HIG"$n被$P『荡剑式』的光环包围，一时不知所措！                      \n" NOR;
                tp = (int)me->query_skill("dugu-sword",1) / 25;
                if (tp<1)
                        tp=2;
                // pk时busy减半
                if (userp(target) && userp(me))
                        tp=tp/2+1;
                target->start_busy(tp);
                me->start_perform_busy(tp+random(10));  } 
        else 
        {
                msg = HIC"\n$N"HIC"手中的剑仿佛幻化无数光芒，跃起腾空向$n"HIC"发出了『荡剑式』。\n"NOR;
                message_vision(msg, me, target);                msg = WHT"可惜$n"WHT"向后一跃，闪过了『荡剑式』的剑光，但是也吓出了一身冷汗。\n"NOR;          me->start_busy(1);
                me->start_perform_busy(1+random(5));
        }       message_vision(msg, me, target);        
return 1;

}
