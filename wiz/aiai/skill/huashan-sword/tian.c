// tian.c

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int damage, wound, i, is_ok;
        int force_cost=random(me->query_skill("sword"))+me->query_skill("sword")/2;
        if( me->query("force",1) < force_cost )
          return notify_fail("�������������\n");
        if( (int)me->query_skill("huashan-sword", 1) < 100 )
                return notify_fail("��Ļ�ɽ������죬�޷�ʹ����������ɡ���\n");
    if( me->query_skill("sword",1) < 20 )
          return notify_fail("��Ļ�������̫���ˡ�\n");
    if( me->query_skill_mapped("force") != "zixia-force" )
          return notify_fail("��������ɡ���Ҫ�����ϼ�񹦷���ʹ�á�\n");
        if( !me->is_fighting() )
          return notify_fail("��������ɡ�Ҫս���в���ʹ�á�\n");
        if(!objectp(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!="sword")
          return notify_fail("��������ɡ�Ҫ�н����ܷ�����\n"); 
        if( target == me )
          return notify_fail("�����ԲУ��ٺ٣�\n");
        if( !target )
          target = offensive_target(me);
        me->add("force",-force_cost );

        msg = HIB "\n$N�����˽���ʹ����ɽ�����ġ�������ɡ���������������$n"HIB"��ȥ��\n"NOR;
    message_vision(msg, me, target);

        is_ok = ((int)random(me->query("combat_exp",1)) > 
                 (int)target->query("combat_exp",1)/
                 ((me->query_skill("dugu-sword",1)+
                 me->query_skill("sword",1)+1)/200+1.8));

        if ( is_ok )
        {
                damage = (int)((me->query_skill("sword", 1)+
                        me->query_skill("dugu_sword", 1))/5);
                
                // pkʱ�˺��Զ���Ϊnkʱ��60%
                // ��4��
                if (userp(target) && userp(me))
                {
                   damage=(int)target->query("kee");
                   wound=(int)target->query("eff_kee");
                   for (i=0;i<4+random(3);i++)
                   {
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
                   for (i=0;i<4+random(3);i++)
                   {
                        COMBAT_D->do_attack(me, target, weapon, TYPE_QUICK);
                    me->add("force", -damage/2);
                   }            
                }

                msg = HIC"\n$n"HIC"��$N"HIC"����ʽɱ�Ĵ��ֲ��������ɵþ����ˡ�\n"NOR;
                me->start_busy(1);
                target->start_busy(random(2)+1);
                me->start_perform_busy(10);
                
                
        } 
        else 
        {
                me->start_busy(1);
                msg = WHT"\n����$p������$P����ͼ���������һԾ������ˡ�������ɡ���\n"NOR;
                me->start_perform_busy(10);
        }
        message_vision(msg, me, target);

        return 1;
}

