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
                return notify_fail(HIC"���¾Ž�[����ʽ]"+"ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( ( myskill = (int)me->query_skill("dugu-sword",1)) < 200)
                return notify_fail("���[���¾Ž�]���л�ԶԶ�������޷���Ԧ�ɽ���\n");
        if( (int)me->query("force")< 400 )
                return notify_fail("�����������,�޷�������\n");
                if( (int)me->query("kee") < 10 ||(int)me->query("sen")<10 ||(int)me->query("gin")<10)
               return notify_fail("��ľ������㣬�޷�ʹ��[����ʽ]��\n");
        
        me->receive_damage("sen", 10);
        me->receive_damage("gin", 10);
        me->receive_damage("kee", 10);
        me->add("force", -400);
        msg = HIB"$N�����ζ���һ��������ס��ȫ��һ��������ɫ����Ľ������ּ��������\n\n"NOR;
        message_vision(msg,me);
        limbs=target->query("limbs");
        me->start_busy(2);
        texp = target->query("combat_exp");
        totalexp = texp + me->query("combat_exp");
 
        if( random(totalexp) > texp ) {
                msg = "$N����ǰ�ľ��񺧵����������ѵ����Ǵ�˵�е�[����ʽ]?!!\n\n";
                message_vision(msg, target);
                size=(int)((myskill)/6);
                damage=random(size)+size+5;
                damage+=
                me->query_str()/3+random(me->query_temp("apply/damage"));
                damage/=2;
        
                size = random(size/2);  
                for(i=0;i<=size;i++)
                        {
                        msg =HIG"������$N��������������ƿ�������������$N��"+limbs[random(sizeof(limbs))]+"...\n"
                            +HIR"����һ���������ط�......\n"NOR;
                        message_vision(msg,target);
                        target->receive_damage("kee",damage,me);
                        target->receive_wound("kee",damage/3,me);
                        }
                COMBAT_D->report_status(target);
                return 1;
        } else {
                msg = HIY"����$N���������У�һ������ȴ�Ѷ���һ�ԡ�\n" NOR;
        }
        message_vision(msg, target);
        return 1;
}
