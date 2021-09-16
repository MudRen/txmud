// zui.c
// 醉忆箩 zui
// 醉月明花掌(zuiyue-strike)的特攻

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,ap,dp,damage;
	string limb,*limbs;

	if(me->is_busy())
		return notify_fail("你上一个动作没有完成，无法使用『醉忆箩』。\n");

	if((skill = me->query_skill("zuiyue-strike",1)) < 100)
		return notify_fail("你醉月明花掌不够纯熟，无法使用『醉忆箩』。\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("『醉忆箩』只能对战斗中的对手使用。\n");

	num = (skill - 100)/50 + 1;
	if(num > 5)
		num = 5;

	force = 100 + (num * 50);

	if(me->query("force") < force)
		return notify_fail("你目前的内力不够，无法施展『醉忆箩』。\n");

	me->add("force",-force);
	me->start_busy(1);

	ap = COMBAT_D->skill_power(me,"unarmed",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE);

	if( !arrayp(limbs = target->query("limbs")) )
		return notify_fail("对手部位错误！请通知巫师处理。\n");

	limb = limbs[random(sizeof(limbs))];

	message_vision(sprintf(BWHT HIB"\n$N拧身趋步施展出菲雨绝学『醉忆箩』。。。\n单掌无声无息的拍向$n的%s\n\n"NOR,
		limb),me,target);

	if(random(ap + dp) < dp) // 失败
	{
		message_vision("$n一缩身，堪堪避开了$N的招式。\n\n",me,target);
		return 1;
	}

	damage = 50 + num*50;
	damage = damage/2 + random(damage/2);

	message_vision("$N只觉得一阵晕眩，两眼发花。\n\n",target);

	target->receive_damage("gin",damage,me);
	target->receive_damage("sen",damage,me);

	damage /= 5;

	target->receive_wound("gin",damage,me);
	target->receive_wound("sen",damage,me);

	COMBAT_D->report_status(target);

	// start_perform_busy() 为使用 perform 的间隔，单位为心跳数。
	// 每个 perform 必须有此设置，即：perform 是不能连续使用的。
	me->start_perform_busy(12);
	return 1;
}
