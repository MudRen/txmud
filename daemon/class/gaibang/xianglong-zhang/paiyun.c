// 排云双掌
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int j;

	j = me->query_skill("xianglong-zhang")/2;
	if( !target ) target = offensive_target(me);
	if( !target || !me->is_fighting(target) || !living(target))
                return notify_fail("「排云双掌」只能在战斗中对对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「排云双掌」！\n");

        if( (int)me->query_skill("xianglong-zhang", 1) < 160 )
                return notify_fail("你的降龙十八掌还不够娴熟，使不出「排云双掌」绝技。\n");

        if( (int)me->query_skill("gaibang-force", 1) < 160 )
                return notify_fail("你的丐帮心法等级还不够，使不出「排云双掌」绝技。\n");

        if (me->query_skill_mapped("force") != "gaibang-force")
                return notify_fail("你所使用的内功不对。\n");
        if( (int)me->query_skill("force") < 200 )
                return notify_fail("你的内功等级不够，不能使用「排云双掌」。\n");

        if( (int)me->query_str() < 24 )
                return notify_fail("你的膂力还不够强劲，使不出「排云双掌」来。\n");

        if (me->query_skill_mapped("unarmed") != "xianglong-zhang"
        || me->query_skill_mapped("parry") != "xianglong-zhang")
                return notify_fail("你现在无法使用「排云双掌」！\n");                                                                                 

	if( (int)me->query("max_force") < 1200)
		return notify_fail("你现在内力太弱，使不出「排云双掌」。\n");     

	if( (int)me->query("force") < 800 )
		return notify_fail("你现在真气太弱，使不出「排云双掌」。\n");

//	if((int)me->query_temp("xlz") ) 
//		return notify_fail("你正在使用降龙啸。\n");

        message_vision(WHT"\n$N一声断喝，双掌齐出，挟起满天飞沙！使的正是萧峰的得意功夫「排云双掌」！\n"NOR,me);

        me->add_temp("apply/unarmed", j);
        me->add_temp("apply/damage", j);
        me->add_temp("apply/attack", j/2);

	for(int i=0;i<6;i++)
	{
		COMBAT_D->do_attack(me,target,TYPE_QUICK);
		target->receive_wound("sen", 10);
	}

        me->add_temp("apply/unarmed", -j);
        me->add_temp("apply/damage", -j);
        me->add_temp("apply/attack", -j/2);
        me->add("force", -600);
        me->add("gin", -100);
        me->start_busy(2);
        target->start_busy(1+random(2));
        return 1;
}
