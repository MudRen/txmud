// xiangmo.c
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	if(!target) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("天将降魔只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("feitian-zhang", 1) < 100 )
		return notify_fail("你的飞天杖法不够娴熟，不会使用「天将降魔」。\n");
	if( (int)me->query_skill("gaibang-force", 1) < 100 )
		return notify_fail("你的丐帮心法不够高，不能使用飞杖伤敌。\n");

	if( (int)me->query("max_force", 1) < 600 )
		return notify_fail("你的内力修为不够，不能使用「天将降魔」。\n");

	if ((int)me->query("force",1) < 400)
		return notify_fail("你的真气不够，无法使用飞杖。\n");

	if( (int)me->query_str() < 30 )
		return notify_fail("你臂力不够，掷不出飞杖。\n");

	msg = HIW"\n$N突然把"+weapon->name()+HIW"交左手，猛吸一口气，"+weapon->query("name")+ HIW "凌空掷向$n。\n\n"NOR;

	if(random(me->query("combat_exp")) > target->query("combat_exp")/3)
	{
	msg += HIR"$n" HIR "猛见金光一闪，急忙闪身躲避，但只觉一股大力铺天盖地般压来，\n登时眼前一花，两耳轰鸣,哇的喷出一口鲜血！！\n\n"NOR;

	damage = (int)me->query_skill("fengmo-zhang", 1);
	damage = damage +  (int)me->query_skill("staff", 1);
	damage=damage/3+random(damage);
	target->receive_damage("kee", damage);
	target->receive_wound("kee", random(damage/3));
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	me->add("force", -damage);
	target->start_busy(1);
	}
	else 
	{
	msg += HIW"可是$p见事不妙，猛地向前一跃,跳出了$P的攻击范围。\n\n"NOR;
	me->add("force", -200);
	me->start_busy(1);
	}
	message_vision(msg, me, target);
	me->start_perform_busy(8);
	return 1;
}
