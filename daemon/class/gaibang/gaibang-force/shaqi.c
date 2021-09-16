// shaqi.c
// 
#include <ansi.h>
inherit SSERVER;
int exert(object me, object target)
{
        string msg,*limbs;
        int i,size,damage;
        int totalexp, texp;
        int myskill;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC"独孤九剑[御剑式]"+"只能对战斗中的对手使用。\n"NOR);
        if( ( myskill = (int)me->query_skill("dugu-sword",1)) < 200)
                return notify_fail("你的[独孤九剑]修行还远远不够，无法驾驭飞剑。\n");
        if( (int)me->query("force")< 400 )
                return notify_fail("你的内力不够,无法出剑。\n");
                if( (int)me->query("kee") < 10 ||(int)me->query("sen")<10 ||(int)me->query("gin")<10)
               return notify_fail("你的精气神不足，无法使出[御剑式]。\n");
        
        me->receive_damage("sen", 10);
        me->receive_damage("gin", 10);
        me->receive_damage("kee", 10);
        me->add("force", -400);
        msg = HIB"$N气贯任督，一股紫气罩住了全身，一把闪着紫色寒光的剑竟脱手激射而出！\n\n"NOR;
        message_vision(msg,me);
        limbs=target->query("limbs");
        me->start_busy(2);
        texp = target->query("combat_exp");
        totalexp = texp + me->query("combat_exp");
 
        if( random(totalexp) > texp ) {
                msg = "$N被眼前的景像骇的楞了神！这难道就是传说中的[御剑式]?!!\n\n";
                message_vision(msg, target);
                size=(int)((myskill)/6);
                damage=random(size)+size+5;
                damage+=
                me->query_str()/3+random(me->query_temp("apply/damage"));
                damage/=2;
        
                size = random(size/2);  
                for(i=0;i<=size;i++)
                        {
                        msg =HIG"剑竞向$N激射而出！剑气破空哧哧作响射入$N的"+limbs[random(sizeof(limbs))]+"...\n"
                            +HIR"剑光一闪，御剑回飞......\n"NOR;
                        message_vision(msg,target);
                        target->receive_damage("kee",damage,me);
                        target->receive_wound("kee",damage/3,me);
                        }
                COMBAT_D->report_status(target);
                return 1;
        } else {
                msg = HIY"可是$N看破了这招，一个飞纵却已躲在一旁。\n" NOR;
        }
        message_vision(msg, target);
        return 1;
}
