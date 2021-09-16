// yujian.c 驭剑飞行
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
        object weapon;
	
	weapon = me->query_temp("weapon");

	if (! target) target = offensive_target(me);

        if (me->query_skill_mapped("force") != "taxue-force")
                return notify_fail("「驭剑术」需要使用踏雪神功。\n"); 

        if(me->query_skill("taxue-force", 1) < 300 )
                return notify_fail("你的踏雪神功还不够娴熟，使不出「驭剑术」绝技。\n");

        if(me->query_skill("fenghui-sword", 1) < 300 )
                return notify_fail("你的风回雪舞剑法还不够娴熟，使不出「驭剑术」绝技。\n");

        if ((int)me->query("max_force", 1) < 3000)
		return notify_fail("你现在内力太弱，不能使用驭剑术。\n");

        if ((int)me->query("force", 1) < 1000)
		return notify_fail("你现在真气太弱，不能使用驭剑术。\n");

        if ((int)me->query("max_mana", 1) < 1500)
		return notify_fail("你现在法术太差，不能使用驭剑术。\n");

        if ((int)me->query("mana", 1) < 1000)
		return notify_fail("你现在法力太弱，不能使用驭剑术。\n");

        if ((int)me->query("max_atman", 1) < 1500)
		return notify_fail("你现在灵力太差，不能使用驭剑术。\n");

        if ((int)me->query("atman", 1) < 1000)
		return notify_fail("你现在灵力太弱，不能使用驭剑术。\n");

	if (!me->query("taxue/yujian_pass"))
		return notify_fail("你现在还不会使用驭剑术。\n");

	message_vision (HIR"\n\n$N左手置于胸前，食指垂直指向天空，口中念念有词，突然大喝一声：“起！”\n\n顷刻间，从天际边飞来一柄利剑，$N一个“仙鹤展翅”，顺手把它操在手中！\n\n"NOR, me);

	new("/d/taxue/obj/sword1")->move(me);

	me->add("force",-400);
	me->add("mana",-300);
	me->add("atman",-300);
	me->start_busy(2);
	return 1;
}