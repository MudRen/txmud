// chuanyun.c
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
      if( !target ) target = offensive_target(me);
     
      if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
      return notify_fail("�������û��ֻ����ս���жԶ���ʹ�á�\n");
             
      if( objectp(me->query_temp("weapon")) )
      return notify_fail("��������ʹ�á������û����\n");
      
      if( (int)me->query_skill("chuanyun-zhang",1) < 120 )
      return notify_fail("��Ĵ��ƴ߻��Ʋ�����죬����ʹ�á������û����\n");
      
      if(userp(me) && (int)me->query_skill("taxue-force",1) < 100 )
      return notify_fail("���̤ѩ�񹦵ȼ�����������ʹ�á������û����\n");  
      
      if(userp(me) && ! me->query_skill("taxue-force"))
      if(userp(me) && me->query_skill_mapped("force") != "taxue-force")
      return notify_fail("��û��̤ѩ���ڹ����޷�ʹ�á������û�����й�����\n"); 
    
      if( (int)me->query_con() < 25 )
      return notify_fail("������岻��ǿ׳������ʹ�á������û����\n");
      
      if( (int)me->query("max_force") < 800 )
      return notify_fail("�������̫��������ʹ�á������û����\n");
      
      if( (int)me->query("force") < 600 )
         return notify_fail("�������̫���ˣ��޷�ʹ�ó��������û����\n");   
                                                                                 
      if (me->query_skill_mapped("unarmed") != "chuanyun-zhang")
                return notify_fail("�������޷�ʹ�á������û�����й�����\n");                                                       
      if(target->query_temp("guimo"))
          return notify_fail("�Է��Ѿ����ܡ������û�����㲻�÷Ѿ��ˣ�\n");
      
      message_vision(HIR"\nͻȻ$N���侫�⣬˫�ֺ�ʮ��������Ȼ����һ�֣�˫�ƶ�ʱ�����\n��Ʈ�ݣ��鶯�쳣����ʱ�����������Ӱ��$n���˹�ȥ��\n\n"NOR,me, target);
     if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2 ||
         random((int)me->query_skill("force")) > (int)target->query_skill("force")/2){         
            me->add("force", -400);
            me->add("gin", -50);
            me->start_busy(1);
            target->start_busy(1);
            if(me->query("force")*2 < target->query("force"))  
                 tell_object(me, HIW"��ֻ��"+target->name()+"����������ǿ���㰵�������ڵĸ������������Ͳ���ȥ��\n"NOR);
            else{
                 tell_object(me, HIR"�ڸ�һ����"+target->name()+"������ʱ����㰵�������������������̺������ڵ��������˹�ȥ��\n"NOR);
                 tell_object(target, HIR"��һ���ۣ�ֻ��"+me->name()+"�������Ӱ���Ѿ�����������ϣ����ż���˵�����İ���˳�ƴ��˹�����\n"NOR);
                 target->set_temp("guimo", 1);
                 target->add_temp("apply/dexerity", -(target->query("dex", 1)/2));  
                 target->add_temp("apply/intelligence", -(target->query("int", 1)/2));    
                 target->add_temp("apply/constitution", -(target->query("con", 1)/2));  
                 target->apply_condition("guimo_poison", 10+target->query_condition("guimo_poison"));
                 target->start_call_out( (: call_other, __FILE__, "remove_effect", target :), me->query_skill("force")/2); 
                }
            target->receive_damage("kee", (int)me->query_skill("force")*2); 
	    target->receive_damage("gin", (int)me->query_skill("force")/3);
            me->start_perform_busy(8); 
            } 
            else 
               {       
                me->start_busy(1);
                me->add("force", -(100+random(100))); 
                me->add("gin", -80);             
                message_vision(MAG"ֻ��$n����һת���Ѿ��Ƶ���$N��󡣶�$Nȴ������ղ��ܿ��ƣ�ͷ��ѣ�Σ�\n\n"NOR, me, target);
               }
           me->start_perform_busy(8); 
           return 1;
}

void remove_effect(object target)
{
      if(!target) return;  
      target->add_temp("apply/dexerity", target->query("dex", 1)/2);  
      target->add_temp("apply/intelligence", target->query("int", 1)/2);    
      target->add_temp("apply/constitution", target->query("con", 1)/2);   
      target->delete_temp("guimo");
      tell_object(target, HIW"���ڣ������Ǽ��ɰ����ڱ鲼���ȫ���ʼ����ɢȥ�ˡ�\n"NOR);
}
