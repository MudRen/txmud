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
          return notify_fail("�㻹û�����򵽡�����ʽ����\n");
        }
        if(!objectp(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!="sword")
        {
          return notify_fail("������ʽ��Ҫ�н����ܷ�����\n");   
        }
        if( me->query("force") < force_cost )   {
          return notify_fail("�������������\n");
        }    if( me->query_skill("sword",1) < 180 )     {
          return notify_fail("��Ļ�������̫���ˡ�\n");
        }       if( !me->is_fighting() )        {
          return notify_fail("������ʽ��Ҫս���в���ʹ�á�\n");
        }       if( target == me )      {
          return notify_fail("�����ԲУ��ٺ٣�\n");
        }       if( !target )     target = offensive_target(me);        me->add("force",-force_cost );
        msg = HIG "\n$N"HIG"�����˽���ʹ�����¾Ž��ġ�����ʽ����������������$n"HIG"��ȥ��\n"NOR;
    message_vision(msg, me, target);

        // �ɹ�����  
        // 1. sword 180, dugu 180  ����exp���� ��3�� �� ��5��
        //    �ɹ���Ϊ�� 1% �� 92%
        // 2. exp��ͬʱ sword,dugu ��180 to 500
        //    �ɹ���Ϊ�� 61% �� 93%
        // 3. �������仯ʱ�ɹ���ƽ��Ϊ 70% (exp���ʮ���������)

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

    if (me->query("id")=="master feng") // fengһ���������
           is_ok=1;

    if ( is_ok )
        {
                // pkʱ�˺��Զ���Ϊnkʱ��60%
                // ��3��5��
                if (userp(target) && userp(me))
                {
                   damage=(int)target->query("kee");
                   wound=(int)target->query("eff_kee");
                   tp=3+random(3);
                   for (i=0;i<tp;i++)
                   {
                        if (!i)
               message_vision(HIG"\n����������ʽ����ʽ��"NOR, me, target);
                        else if (i<4)
                           message_vision(HIG"\n����������ʽ����"+chinese_number(i)+"����"NOR, me, target);
                        else
                        {
               message_vision(HIR"\n����������ʽ���սὣ����"NOR, me, target);
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
                   // fengһ�������5��
                   if (me->query("id")=="master feng")  // fengһ�����5��
                           tp=5;
                   for (i=0;i<tp;i++)
                   {
                        if (!i)
               message_vision(HIG"\n����������ʽ����ʽ��"NOR, me, target);
                        else if (i<4)
                           message_vision(HIG"\n����������ʽ����"+chinese_number(i)+"����"NOR, me, target);
                        else
                        {
               message_vision(HIR"\n����������ʽ���սὣ����"NOR, me, target);
                           COMBAT_D->do_attack(me, target, weapon, TYPE_QUICK);
                        }
                        COMBAT_D->do_attack(me, target, weapon, TYPE_QUICK);
                    me->add("force", -damage/2);
                   }            
                }
                msg = HIG"\n$n"HIG"��$N"HIG"����ʽɱ�Ĵ��ֲ���������һ�¡�\n"NOR;
                target->start_busy(random(2)+1);
                me->start_perform_busy(8);
        } 
        else 
        {
                msg = WHT"\n����$p������$P����ͼ���������һԾ������ˡ�����ʽ����\n"NOR;
                me->start_perform_busy(5);
        }
        message_vision(msg, me, target);
        return 1;
}
