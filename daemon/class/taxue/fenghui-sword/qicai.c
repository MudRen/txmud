// qicai.c  
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int damage,msen;
        object weapon;

        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target 
	|| !target->is_character()
	|| !me->is_fighting(target) )
                return notify_fail("���߲ʷɽ���ֻ����ս���жԶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "fenghui-sword")
                return notify_fail("�������ʹ�ý�ʱ����ʹ�����߲ʷɽ�����\n");

        if(me->query_skill("fenghui-sword", 1) < 100 )
                return notify_fail("��ķ��ѩ�轣����������죬ʹ�������߲ʷɽ���������\n");

        if(me->query_skill("taxue-force", 1) < 100 )
                return notify_fail("���̤ѩ�񹦻�������죬ʹ�������߲ʷɽ���������\n");

	if(me->query_skill("dodge", 1)  < 100)
                return notify_fail("�����������Ѹ�ͣ�ʹ�������߲ʷɽ���������\n");

        if(me->query_skill("force") < 100 )
                return notify_fail("����ڹ��ȼ�������ʹ�������߲ʷɽ���������\n");

        if(me->query_str() < 30)
                return notify_fail("�������������ǿ����ʹ�������߲ʷɽ���������\n");

        if (me->query_skill_mapped("force") != "taxue-force")
                return notify_fail("���߲ʷɽ�����Ҫʹ��̤ѩ�񹦡�\n");                                                                                 

        if(me->query("max_force") < 800 )
                return notify_fail("����������̫����ʹ�������߲ʷɽ�����\n");      

        if(me->query("force") < 500+(int)me->query("force_factor")*4 )
                return notify_fail("����������̫����ʹ�������߲ʷɽ�����\n");

	damage =((int)me->query("str")/3 +(int)me->query("force_factor")/10)* (int)me->query_skill("fenghui-sword")/40;

	msen = target->query("max_sen")/20;

        if(weapon->query("id") == "ganjiang sword")
	{
        me->add_temp("apply/damage", 50);
        }

        me->set_temp("qicai", 1);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 || random(me->query("force")) > target->query("force")/2 )
	{

        message_vision (HIR"\n$N���з��ѩ�轣�����������Ƴ�������⣬�����н���Ϊ�߲�ϼ�⣬\n�γɱ����������Σ�ֱָ$n��\n\n"NOR, me, target);

	COMBAT_D->do_attack(me,target,TYPE_QUICK);   

	if(me->query_temp("qicai"))
          message_vision(HIY"                                                                     ����  ��  ����\n"NOR,me);  
	COMBAT_D->do_attack(me,target,TYPE_QUICK);     
        me->add("force", -120);  
        me->add("gin", -10);
//	target->receive_damage("kee",damage,me);

        if(me->query_temp("qicai"))
          message_vision(HIY"                                                                     ����  ��  ����\n"NOR,me);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);

        me->add("force", -120);
        me->add("gin", -10);
//	target->receive_damage("kee",damage,me);

        if(me->query_temp("qicai"))
          message_vision(HIY"                                                                     ����  ��  ����\n"NOR,me);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
        me->add("force", -120);  
        me->add("gin", -10);
//	target->receive_damage("kee",damage,me);

        if(me->query_temp("qicai"))
        message_vision(HIY"                                                                     ����  ��  ����\n"NOR,me);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
        me->add("force", -120);  
        me->add("gin", -10);

//	target->receive_damage("kee",damage,me);
	target->receive_wound("sen", msen, me);

        me->delete_temp("qicai");
      	}

	else 
	{
        message_vision (HIW"$N���һ�������з��ѩ�轣����������ͻȻ��$N�о���ָ��������ǰ������һ����\n$n" HIW "ʧȥ����Ӱ��$N��æ����������Ҳ������һ���亹��\n\n"NOR, me, target); 
        me->add("force", -300);         
	me->start_busy(1);
	}

	me->start_perform_busy(10);
	return 1;
}