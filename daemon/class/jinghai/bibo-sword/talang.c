// talang.c
// bibo-sword 的特攻

#include <ansi.h>

#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int extra, rir, force;

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	extra = me->query_skill("bibo-sword",1);

	if ( extra < 60)
		return notify_fail("你的『碧波剑法』还不够纯熟！\n");

	if( !target )
		target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
                return notify_fail("『碧波踏浪』只能对战斗中的对手使用。\n");

	if( (force = me->query("force")) <= 100 )
		return notify_fail("你的内力不足，无法使用『碧波踏浪』。\n");

	rir = target->query_skill("dodge",1);

	message_vision(HIG"$N使出『碧波剑法』之不传之秘『碧波踏浪』。\n"NOR,me);

	if(random(me->query("combat_exp")*(extra/10+1))>target->query("combat_exp")*(rir/30+1))
	{
		int n,i;

		message_vision(HIG "$N一声长啸，身形冲天而起，右手中一个剑决使出连连刺出数剑,左手画了个半圆护住空门！\n" NOR,me,target);

		if(extra > 250)
			n = 5;
		else if(extra > 200)
			n = 4;
		else if(extra > 120)
			n = 3;
		else
			n = 2;

		if(force < (n*100))
			n = to_int(force/100);

		for(i=0;i<n;i++)
			COMBAT_D->do_attack(me,target,TYPE_QUICK);

		message_vision(sprintf(HIC "\n$N暗运劲气陡然攻出%s招,$n被剑气射了个手忙脚乱！\n\n" NOR,
			chinese_number(n)),me,target);

		n--;
		me->add("force",-n*100);
		me->receive_damage("sen",n*10,"tire");
	}

	else
	{
		message_vision("\n但$n看破$N的意图，趁势发动攻击！\n\n",me,target);
		COMBAT_D->do_attack(target,me,TYPE_QUICK);
		me->add("force",-100);
	}

	target->start_busy(1);
	me->start_busy(1);
	me->start_perform_busy(8);
	return 1;
}
