
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
                return notify_fail("「御剑式」只能在战斗中对对手使用。\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "dugu-sword")
                return notify_fail("你必须在使用剑时才能使出「御剑式」！\n");

        if(me->query_skill("dugu-sword", 1) < 100 )
                return notify_fail("你的「独孤九剑」还不够娴熟，使不出「御剑式」绝技。\n");
	
	
        if(me->query_skill("force",1) < 100 )
                return notify_fail("你的内力不足，使不出「御剑式」绝技。\n");

        if(me->query_str() < 25)
                return notify_fail("你的膂力还不够强劲，使不出「御剑式」绝技。\n");                                                                        
 	
 	j=(int)((me->query_skill("dugu-sword", 1))/50);
        if(me->query("force") < 100+(int)me->query("force_factor")*j )
                return notify_fail("你现在内力不足，使不出「御剑式」。\n");

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

        message_vision (HIB"$N气贯任督，一股紫气罩住了全身，一把闪着紫色寒光的剑竟脱手激射而出！\n"NOR, me, target);
	
	
	for(i=0;i<=j;i++)
	{
        if(me->query_temp("yujian"))
             
        me->add("force", -100);  
        // me->add("gin", -10);
	target->receive_damage("kee",damage,me);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	message_vision(HIY"剑光一闪，御剑回飞......\n"NOR,me);  
	}
	target->start_busy(1);
	me->delete_temp("yujian_pfm");
	me->start_perform_busy(8);
	return 1;
      	}

      else 
	{
        message_vision (HIY"$N使用失败。\n\n"NOR, me, target);        
	me->start_busy(1);
	return 1;
	}
	

}