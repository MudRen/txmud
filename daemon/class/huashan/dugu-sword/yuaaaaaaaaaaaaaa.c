
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int i,j,damage,msen;
        object weapon;
        
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target|| !target->is_character()|| !me->is_fighting(target) )
                return notify_fail("������ʽ��ֻ����ս���жԶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "dugu-sword")
                return notify_fail("�������ʹ�ý�ʱ����ʹ��������ʽ����\n");

        if(me->query_skill("dugu-sword", 1) < 100 )
                return notify_fail("��ġ����¾Ž�����������죬ʹ����������ʽ��������\n");
	
	
        if(me->query_skill("force",1) < 100 )
                return notify_fail("����������㣬ʹ����������ʽ��������\n");

        if(me->query_str() < 25)
                return notify_fail("�������������ǿ����ʹ����������ʽ��������\n");                                                                        
 	
 	j=(int)((me->query_skill("dugu-sword", 1))/50);
        if(me->query("force") < 100+(int)me->query("force_factor")*j )
                return notify_fail("�������������㣬ʹ����������ʽ����\n");

	damage =((int)me->query("str")/3 +(int)me->query("force_factor")/5)* (int)me->query_skill("dugu-sword")/15;

	msen = target->query("max_sen")/20;


        me->add_temp("apply/damage", 50);
        me->set_temp("yujian", 1);
	me->add_temp("yujian_pfm");
        me->add("force", -100);
        me->add("gin", -5); 
        
        
	target->receive_damage("kee",damage,me);
        target->receive_wound("sen", msen, me);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5)
     	{

        message_vision (HIB"$N�����ζ���һ��������ס��ȫ��һ��������ɫ����Ľ������ּ��������\n"NOR, me, target);
	
	
	for(i=0;i<=j;i++)
	{
        if(me->query_temp("yujian"))
             
        me->add("force", -100);  
        // me->add("gin", -10);
	target->receive_damage("kee",damage,me);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	message_vision(HIY"����һ���������ط�......\n"NOR,me);  
	}
	target->start_busy(1);
	me->delete_temp("yujian_pfm");
	me->start_perform_busy(8);
	return 1;
      	}

      else 
	{
        message_vision (HIY"$Nʹ��ʧ�ܡ�\n\n"NOR, me, target);        
	me->start_busy(1);
	return 1;
	}
	

}