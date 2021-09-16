// yujian.c

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
        int tp; int damage, wound, i;
        object weapon;
        string msg;
        int is_ok=0;

        int force_cost=random(me->query_skill("sword"))+me->query_skill("sword")/2;
        if( !me->query("dugu_pfm_yujian") )
        {
          return notify_fail("你还没有领悟到『御剑式』。\n");
        }
        if(!objectp(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!="sword")
        {
          return notify_fail("『御剑式』要有剑才能发出。\n");   
        }
        if( me->query("force") < force_cost )   {
          return notify_fail("你的内力不够。\n");
        }    if( me->query_skill("sword",1) < 180 )     {
          return notify_fail("你的基本剑术太差了。\n");
        }       if( !me->is_fighting() )        {
          return notify_fail("『御剑式』要战斗中才能使用。\n");
        }       if( target == me )      {
          return notify_fail("你想自残？嘿嘿！\n");
        }       if( !target )     target = offensive_target(me);        me->add("force",-force_cost );
        msg = HIG "\n$N"HIG"轻轻运剑，使出独孤九剑的『御剑式』，剑锋凌厉的向$n"HIG"攻去。\n"NOR;
    message_vision(msg, me, target);

        // 成功几率  
        // 1. sword 180, dugu 180  敌我exp差距从 敌3倍 到 我5倍
        //    成功率为从 1% 到 92%
        // 2. exp相同时 sword,dugu 从180 to 500
        //    成功率为从 61% 到 93%
        // 3. 都递增变化时成功率平均为 70% (exp相差十分悬殊除外)

        /*
        tp=0;
        for (i=0;i<1000;i++)
        {
    if ( (int)random(me->query("combat_exp",1)) > 
                 (int)target->query("combat_exp",1)/((me->query_skill("dugu-sword",1)+me->query_skill("sword",1)+1)/200+1.8) )
                 tp++;
        }
        printf("DEBUG: OK times of 1000 is %d \n",tp);
        */
        
        me->start_busy(1);

        is_ok = ((int)random(me->query("combat_exp",1)) > 
                 (int)target->query("combat_exp",1)/
                 ((me->query_skill("dugu-sword",1)+
                 me->query_skill("sword",1)+1)/200+1.8));

    if (me->query("id")=="master feng") // feng一定会击中你
           is_ok=1;

    if ( is_ok )
        {
                // pk时伤害自动降为nk时的60%
                // 打3至5招
                if (userp(target) && userp(me))
                {
                   damage=(int)target->query("kee");
                   wound=(int)target->query("eff_kee");
                   tp=3+random(3);
                   for (i=0;i<tp;i++)
                   {
                        if (!i)
               message_vision(HIG"\n——『御剑式』起式："NOR, me, target);
                        else if (i<4)
                           message_vision(HIG"\n——『御剑式』第"+chinese_number(i)+"剑："NOR, me, target);
                        else
                        {
               message_vision(HIR"\n——『御剑式』终结剑技："NOR, me, target);
                           COMBAT_D->do_attack(me, target, weapon, TYPE_QUICK);
                        }
                        COMBAT_D->do_attack(me, target, weapon, TYPE_QUICK);
            
                        wound -= (int)target->query("eff_kee");
                //printf(HIW"DEBUG: wound restore = %d \n"NOR, (int)wound*3/5);
                        if (wound>=0)
                        {
                                wound =  (int)target->query("eff_kee") + (int)wound*3/5;
                                target->set("eff_kee", wound);
                        }

                        damage -= (int)target->query("kee");
                        //printf(HIW"DEBUG: damage restore = %d \n"NOR, (int)damage*3/5);
                        if (damage>=0)
                        {
                                damage =  (int)target->query("kee") + (int)damage*3/5;
                                target->set("kee", damage);
                        }

                        damage=(int)target->query("kee");
                    wound=(int)target->query("eff_kee");

                    me->add("force", -damage/2);
                   }            
                }
                else
                {
                   tp=3+random(3);
                   // feng一定会击中5下
                   if (me->query("id")=="master feng")  // feng一定会出5剑
                           tp=5;
                   for (i=0;i<tp;i++)
                   {
                        if (!i)
               message_vision(HIG"\n——『御剑式』起式："NOR, me, target);
                        else if (i<4)
                           message_vision(HIG"\n——『御剑式』第"+chinese_number(i)+"剑："NOR, me, target);
                        else
                        {
               message_vision(HIR"\n——『御剑式』终结剑技："NOR, me, target);
                           COMBAT_D->do_attack(me, target, weapon, TYPE_QUICK);
                        }
                        COMBAT_D->do_attack(me, target, weapon, TYPE_QUICK);
                    me->add("force", -damage/2);
                   }            
                }
                msg = HIG"\n$n"HIG"被$N"HIG"的招式杀的措手不及，楞了一下。\n"NOR;
                target->start_busy(random(2)+1);
                me->start_perform_busy(8);
        } 
        else 
        {
                msg = WHT"\n可是$p看破了$P的企图，向后纵身一跃，躲过了『御剑式』。\n"NOR;
                me->start_perform_busy(5);
        }
        message_vision(msg, me, target);
        return 1;
}
