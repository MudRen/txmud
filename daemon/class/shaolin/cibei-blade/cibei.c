// cibei.c
// 我佛慈悲 cibei
// 慈悲刀(cibei-blade)的特攻

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,my_force,ap,dp;
	object weapon;

	if(me->is_busy())
		return notify_fail("你上一个动作没有完成，无法使用『我佛慈悲』。\n");

	if((skill = me->query_skill("cibei-blade",1)) < 100)
		return notify_fail("你慈悲刀法不够纯熟，无法使用『我佛慈悲』。\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("『我佛慈悲』只能对战斗中的对手使用。\n");

	my_force = me->query("force");

	if(skill >= 250)
	{
		num = 12; force = 500;
	}

	else if(skill >= 170)
	{
		num = 7; force = 350;
	}

	else
	{
		num = 4; force = 150;
	}

	if(my_force < force)
		return notify_fail("你目前的内力不足，无法施展『我佛慈悲』\n");

	if(!weapon = me->query_temp("weapon"))	// stick 是双手兵器。
		return notify_fail("你无法施展『我佛慈悲』\n");

	me->add("force",-force);

	message_vision(sprintf(HIC"\n$N高宣一声佛号，手中%s一圈，幻出一片柔光照向$n。\n"NOR,weapon->name()),me,target);
	ap = COMBAT_D->skill_power(me,"blade",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE);
	if(random(ap + dp) < dp)
		num = 1;
	if(target->query("can_speak"))
		message_vision(sprintf(HIY"\n$N被$n宝像所慑，不觉得一呆%s\n"NOR,
			num == 1?"。":"身形滞涩，两眼迷惘的望着前方。\n"),target,me);
	target->start_busy(num);
	me->start_busy(1);

	// start_perform_busy() 为使用 perform 的间隔，单位为心跳数。
	// 每个 perform 必须有此设置，即：perform 是不能连续使用的。
	me->start_perform_busy(15);
	return 1;
}
