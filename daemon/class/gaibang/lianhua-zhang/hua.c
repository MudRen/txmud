// hua.c
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("花开花落只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用花开花落！\n");  
                
	if( (int)me->query_skill("lianhua-zhang", 1) < 100 )
		return notify_fail("你的莲花掌不够娴熟，不会使用花开花落！\n");
                                
        if( (int)me->query_skill("gaibang-force", 1) < 100 )
                return notify_fail("你的丐帮心法不够高，不能用出花开花落伤敌。\n");

	if ( me->query_skill_mapped("unarmed") != "lianhua-zhang")
               return notify_fail("你现在无法使用「花开花落」进行攻击。\n");                                                                                 
	if((int)me->query("max_force",1) < 600)
		return notify_fail("你的内力修为不够，无法使用「花开花落」。\n");

        if( (int)me->query("force") < 400 )
                return notify_fail("你现在内力太弱，无法使出花开花落。\n");

        msg = HIR"$N面色忽变，步法飘忽不定，口中念念有词：莲花开、莲花落、有人富贵有人落魄......\n手掌幻化为千万个掌影如漫天飘雪，铺天盖地盖向$n。\n"NOR;

	if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
	{
	msg += HIR"\n结果只听“嘣”的一声，$n" HIR "发出如神哭鬼号似的厉啸，鲜血从口中狂喷而出！\n\n"NOR;

	damage = (int)me->query_skill("gaibang-force", 1);
	damage = damage +  (int)me->query_skill("lianhua-zhang", 1);
	damage=damage/3+random(damage);
	target->receive_damage("kee", damage);
	target->receive_wound("kee", random(damage/3));
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	me->add("force", -damage);
	target->start_busy(1);
	}
	else 
	{
	msg += HIW"\n$n" HIW "全力向右一滚，那漫天掌影堪堪擦肩而过，端的是凶险无比！\n\n" NOR;
	me->add("force", -200);
	me->start_busy(1);
	}
	message_vision(msg, me, target);
	me->start_perform_busy(8);
	return 1;
}