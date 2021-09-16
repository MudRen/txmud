// luan.c
// 金刀乱舞

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int extra,msen;
	object weapon;

	if(me->is_busy())
		return 0;

	extra = me->query_skill("lianhuan-blade",1);
	if ( extra < 50)
		return notify_fail("你的连环刀法还不够纯熟！\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("金刀乱舞只能对战斗中的对手使用。\n");

        if (me->query("force")<=100)
		return notify_fail("你的内力不足，无法使用金刀乱舞\n");

	if(!objectp(weapon = me->query_temp("weapon")))
		return 0;

        me->add("force",-100);
        me->start_busy(2);

	message_vision(sprintf(HIY "$N大吼一声，手中%s挽出一个刀花，猛然使出「金刀乱舞」！\n" NOR,weapon->name()),me,target);

	msen = target->query("max_sen")/20;
	message_vision(HIY "上一刀......\n" NOR,me,target);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	target->receive_wound("sen", msen, me);
	message_vision(HIY "下一刀......\n" NOR,me,target);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	target->receive_wound("sen", msen, me);
	message_vision(HIY "左一刀......\n" NOR,me,target);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	target->receive_wound("sen", msen, me);
	message_vision(HIY "右一刀......\n" NOR,me,target);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	target->receive_wound("sen", msen, me);
	message_vision(HIY "中间再来一刀......\n" NOR,me,target);
	COMBAT_D->do_attack(me,target,TYPE_QUICK);
	target->receive_wound("sen", msen, me);

	return 1;
}
