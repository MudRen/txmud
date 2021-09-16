// tian.c
// 天外飞仙 tian
// 华山剑法(huashan-sword)的特攻

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	object weapon;

	if(me->is_busy())
		return notify_fail("你上一个动作没有完成，无法使用『天外飞仙』。\n");

	if(me->query_skill("huashan-sword",1) < 150)
		return notify_fail("你的华山剑法不够纯熟，无法使用『天外飞仙』。\n");

	if(me->query_skill_mapped("force") != "zixia-force")
		return notify_fail("『天外飞仙』需要『紫霞神功』的配合。\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("『天外飞仙』只能对战斗中的对手使用。\n");

	if(me->query("force") < 500)
		return notify_fail("你目前的内力不足，无法施展『天外飞仙』");

	me->add("force",-450);

	if(!weapon = me->query_temp("weapon"))
		return notify_fail("你无法施展『天外飞仙』\n");

	message_vision(sprintf(HIB"\n$N团身挪步，剑走轻灵，脸上紫气一闪，施展出华山绝学『天外飞仙』\n手中%s迅捷无比地向攻去。\n\n"NOR,
		weapon->name()), me, target);

        for(int i=0;i<4;i++)
	{
		COMBAT_D->do_attack(me,target,TYPE_QUICK);
	}

	target->start_busy(1);
	me->start_busy(1);

	// start_perform_busy() 为使用 perform 的间隔，单位为心跳数。
	// 每个 perform 必须由此设置，即：perform 是不能连续使用的。
	me->start_perform_busy(8);
	return 1;
}
