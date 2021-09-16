// sanzan
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「逍遥三斩」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("qimen-blade", 1) < 100 )
		return notify_fail("你的奇门刀法不够娴熟，无法使用「逍遥三斩」。\n");
	if( (int)me->query_skill("gaibang-force", 1) < 80 )
		return notify_fail("你的丐帮心法不够高。\n");

	if((int)me->query("max_force",1)< 600)
		return notify_fail("你的内力修为不够，无法使用「逍遥三斩」。\n");

	if( (int)me->query("force", 1) < 400 )
		return notify_fail("你现在内力太弱，不能使用「逍遥三斩」。\n");

	msg = CYN "$N面色忽变，步法飘忽不定，手腕疾抖，千万个刀花如漫天飘雪，铺天盖地飞向$n。\n\n"NOR;
	if(random(me->query("combat_exp")) > target->query("combat_exp")/3 )
	{
	msg += HIR"只见$N足踏天地人，逍遥三斩光聚为一线，劈向$n,\n$n" HIR "只觉一股热流扑面而来，躲闪不及，连中三刀鲜血狂喷而出！\n\n"NOR;

	damage = (int)me->query_skill("gaibang-force", 1);
	damage = damage +  (int)me->query_skill("qimen-blade", 1);
	damage=damage/3+random(damage);
	target->receive_damage("kee", damage);
	target->receive_wound("kee", random(damage/3));
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	me->add("force", -damage);
	}
	else 
	{
	msg += CYN"可是$p早有防备，笑道：“你在奇门刀法内暗藏逍遥三斩，难道就奈何的了我？\n\n"NOR;
	me->add("force", -200);
	me->start_busy(1);
	}
	message_vision(msg, me, target);
	me->start_perform_busy(8);
	return 1;
}
