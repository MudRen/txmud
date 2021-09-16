// weixiao.c 残花微笑
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object  weapon;
	string  msg;
        int damage,ap;
	
	weapon = me->query_temp("weapon");

	if (! target) target = offensive_target(me);

	if (! target 
	|| !target->is_character() 
	|| ! me->is_fighting(target))
		return notify_fail("残花微笑只能对战斗中的对手使用。\n");
	                        
        if ((int)me->query("force", 1) < 800)
		return notify_fail("你现在内力太弱，不能使用残花微笑。\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "fenghui-sword")
                return notify_fail("你必须在使用剑时才能使出「残花微笑」！\n");

        if (me->query_skill_mapped("force") != "taxue-force")
                return notify_fail("「残花微笑」需要使用踏雪神功。\n"); 

	if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N怀抱" + weapon->name() + HIC "，一圈圈的划向$n，" HIC "将$p卷在当中！\n" NOR;
	me->add("force", -50);

        ap = me->query_skill("fenghui-sword", 1) * 3 / 2 +
             me->query_skill("force", 1);

	damage = ap / 2 + random(ap / 2);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 )
        {
                msg += HIR "$n" HIR "连忙腾挪躲闪，然而“扑哧”一声，" + weapon->name() +"正好击中$p" HIR "的要害，$p" HIR "一声惨叫，连退数步。\n" NOR;            
		target->receive_damage("kee",damage,me);
		me->add("force", -400);
		me->start_busy(1);
	}
	else 
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的变化，见招拆招，没有受到任何伤害。\n"NOR;
                me->add("force", -300);
		me->start_busy(1);
	}

	message_vision(msg, me, target);
	me->start_perform_busy(8);
	return 1;
}
