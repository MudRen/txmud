// dang ����ʽ
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int tp;
        string msg;
        object weapon;
        
        if( !target ) target = offensive_target(me);    if( !me->query("dugu_pfm_dang") )
                return notify_fail("�㻹û���򵽶��¾Ž������裬�޷�ʹ��������ʽ����\n");

        if(!objectp(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!="sword")
          return notify_fail("������ʽ��Ҫ�н����ܷ�����\n");   

        if( !target     ||      !target->is_character() ||      !me->is_fighting(target) )              return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");    if( target->is_busy() )         return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ�������ٳ�������ʽ����\n");                      if( (int)me->query_skill("dugu-sword", 1) < 100 )           return notify_fail("��Ķ��¾Ž�������죬�޷�ʹ��������ʽ����\n");    // �ɹ�����  
        // 1. kar 20, int 20  ����exp���� ��3�� �� ��5��
        //    �ɹ���Ϊ�� 1% �� 92%
        // 2. exp��ͬʱ kar,int ��20 to 60
        //    �ɹ���Ϊ�� 51% �� 90%
        // 3. �������仯ʱ�ɹ���ƽ��Ϊ 70% (exp���ʮ���������)

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
        {       msg = HIG"\n$N"HIG"Ծ���ڿգ����еĽ��·�û�������â����$n"HIG"������             "HIC;
        message_vision(msg, me, target);

msg="
�ߡߡߡߡߡߡ��ߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡ�
�ߡߡߡߡߡߡ����������������������������ߡߡߡߡߡߡߡߡߡߡ�

�ߡߡ������������贈�������������������������ߡߡ�����ʽ���ߡ�
�ߡߡߡߡߡߡ�����������������������������ߡߡߡߡߡߡߡߡߡ�
�ߡߡߡߡߡߡ��ߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡ��ߡߡߡߡߡ�
�ߡߡߡߡߡߡߡߡߡߡߩ����������������������������ߡߡߡߡߡ�
�ߡߡ�����ʽ���ߡߣ��������������������������贈�����������ߡ�
�ߡߡߡߡߡߡߡߡߡߡ੥���������������������������ߡߡߡߡߡ�
�ߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡߡ��ߡߡߡߡߡ�
"NOR;
     message_vision(msg, me, target);
                msg = HIG"$n��$P������ʽ���Ĺ⻷��Χ��һʱ��֪���룡                      \n" NOR;
                tp = (int)me->query_skill("dugu-sword",1) / 25;
                if (tp<1)
                        tp=2;
                // pkʱbusy����
                if (userp(target) && userp(me))
                        tp=tp/2+1;
                target->start_busy(tp);
                me->start_perform_busy(tp+random(10));  } 
        else 
        {
                msg = HIC"\n$N"HIC"���еĽ��·�û�������â��Ծ���ڿ���$n"HIC"�����ˡ�����ʽ����\n"NOR;
                message_vision(msg, me, target);                msg = WHT"��ϧ$n"WHT"���һԾ�������ˡ�����ʽ���Ľ��⣬����Ҳ�ų���һ���亹��\n"NOR;          me->start_busy(1);
                me->start_perform_busy(1+random(5));
        }       message_vision(msg, me, target);        
return 1;

}
