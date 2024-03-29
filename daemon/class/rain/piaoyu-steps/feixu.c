// feixu.c
// 凌花飞絮 feixu
// 飘雨步法(piaoyu-steps)的特攻

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,up,time;

	if(me->is_busy())
		return notify_fail("你上一个动作没有完成，无法使用『凌花飞絮』。\n");

	if(me->query_temp("block-piaoyu-step"))
		return notify_fail("你的身法已经提升至极限，『凌花飞絮』已经没有用处了。\n");

	if((skill = me->query_skill("piaoyu-steps",1)) < 100)
		return notify_fail("你飘雨步法不够纯熟，无法使用『凌花飞絮』。\n");

	num = (skill - 100)/40 + 1;

	force = (num+1)*100;	// 需要的内力
	if(me->query("force") < force)
		return notify_fail("你内力不够，无法使用『凌花飞絮』。\n");

	time = 120 + (30*num);	// 维持的时间
	if(num > 5)
		num = 5;

	up = 10 + (num * 10);

	message_vision(sprintf("$N默念『飘雨步法』的要诀，身形陡转，施展出%s。\n",
		BWHT HIG"『凌花飞絮』"NOR),me);

	me->add_temp("apply/defense",up);
	me->add("force",-force);
	me->set_temp("block-piaoyu-step",1);

	me->start_busy(1);

	// start_perform_busy() 为使用 perform 的间隔，单位为心跳数。
	// 每个 perform 必须有此设置，即：perform 是不能连续使用的。
	me->start_perform_busy(15);

	call_out("stop_up",time,me,up);

	return 1;
}

private void stop_up(object who,int up)
{
	if(!objectp(who) || (up <= 0) )
		return;

	who->add_temp("apply/defense",-up);
	who->delete_temp("block-piaoyu-step");

	tell_object(who,HIG"你感觉身形慢慢的滞重了下来，大概『凌花飞絮』的功效已经消失了。\n"NOR);
}

int clean_up()
{
	if(find_call_out("stop_up") >= 0)
		return 1;
	return ::clean_up();
}
