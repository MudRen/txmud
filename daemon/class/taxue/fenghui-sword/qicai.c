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
                return notify_fail("「七彩飞剑」只能在战斗中对对手使用。\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "fenghui-sword")
                return notify_fail("你必须在使用剑时才能使出「七彩飞剑」！\n");

        if(me->query_skill("fenghui-sword", 1) < 100 )
                return notify_fail("你的风回雪舞剑法还不够娴熟，使不出「七彩飞剑」绝技。\n");

        if(me->query_skill("taxue-force", 1) < 100 )
                return notify_fail("你的踏雪神功还不够娴熟，使不出「七彩飞剑」绝技。\n");

	if(me->query_skill("dodge", 1)  < 100)
                return notify_fail("你的身法还不够迅猛，使不出「七彩飞剑」绝技。\n");

        if(me->query_skill("force") < 100 )
                return notify_fail("你的内功等级不够，使不出「七彩飞剑」绝技。\n");

        if(me->query_str() < 30)
                return notify_fail("你的膂力还不够强劲，使不出「七彩飞剑」绝技。\n");

        if (me->query_skill_mapped("force") != "taxue-force")
                return notify_fail("「七彩飞剑」需要使用踏雪神功。\n");                                                                                 

        if(me->query("max_force") < 800 )
                return notify_fail("你现在内力太弱，使不出「七彩飞剑」。\n");      

        if(me->query("force") < 500+(int)me->query("force_factor")*4 )
                return notify_fail("你现在真气太弱，使不出「七彩飞剑」。\n");

	damage =((int)me->query("str")/3 +(int)me->query("force_factor")/10)* (int)me->query_skill("fenghui-sword")/40;

	msen = target->query("max_sen")/20;

        if(weapon->query("id") == "ganjiang sword")
	{
        me->add_temp("apply/damage", 50);
        }

        me->set_temp("qicai", 1);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 || random(me->query("force")) > target->query("force")/2 )
	{

        message_vision (HIR"\n$N手中风回雪舞剑连划数剑，逼出道道金光，剑光中剑身化为七彩霞光，\n形成北斗七星阵形，直指$n！\n\n"NOR, me, target);

	COMBAT_D->do_attack(me,target,TYPE_QUICK);   

	if(me->query_temp("qicai"))
          message_vision(HIY"                                                                     ※※  七  ※※\n"NOR,me);  
	COMBAT_D->do_attack(me,target,TYPE_QUICK);     
        me->add("force", -120);  
        me->add("gin", -10);
//	target->receive_damage("kee",damage,me);

        if(me->query_temp("qicai"))
          message_vision(HIY"                                                                     ※※  彩  ※※\n"NOR,me);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);

        me->add("force", -120);
        me->add("gin", -10);
//	target->receive_damage("kee",damage,me);

        if(me->query_temp("qicai"))
          message_vision(HIY"                                                                     ※※  飞  ※※\n"NOR,me);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
        me->add("force", -120);  
        me->add("gin", -10);
//	target->receive_damage("kee",damage,me);

        if(me->query_temp("qicai"))
        message_vision(HIY"                                                                     ※※  剑  ※※\n"NOR,me);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
        me->add("force", -120);  
        me->add("gin", -10);

//	target->receive_damage("kee",damage,me);
	target->receive_wound("sen", msen, me);

        me->delete_temp("qicai");
      	}

	else 
	{
        message_vision (HIW"$N大吼一声，手中风回雪舞剑连划数剑，突然，$N感觉剑指无所依，前面亮光一闪，\n$n" HIW "失去了踪影，$N连忙撤剑护身，但也惊出了一身冷汗。\n\n"NOR, me, target); 
        me->add("force", -300);         
	me->start_busy(1);
	}

	me->start_perform_busy(10);
	return 1;
}