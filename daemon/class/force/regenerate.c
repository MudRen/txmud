// regenerate.c

inherit SSERVER;

int exert(object me, object target)
{
	int diff, neilineed;
	int eff,now,ef,f;

	if( target != me )
		return notify_fail("你只能用内功提升自己的精力。\n");

	if( (f = (int)me->query("force")) < 20 )
		return notify_fail("你的内力不够。\n");
	if( (ef = (int)me->query_skill("force")) < 10 )
		return notify_fail("你的内功修为不够。\n");	


	eff = me->query("eff_gin");
	now = me->query("gin");

	diff = eff - now;

	if(diff < 1)
		return notify_fail("你现在精力充沛，不需要行功运气补充。\n");

	neilineed = diff * 50 / ef;

	if(neilineed < 1)
		neilineed = 1;

	if(neilineed > f)
		neilineed = f;
	diff = neilineed * ef / 50;

	if( diff < (eff - now) && neilineed < f )
	{
		neilineed++;
		diff = (eff - now);
	}

	me->receive_heal("gin", diff);
	me->add("force", -neilineed);

	message_vision("$N深深吸了口气，手脚活动了几下，整个人看起来有活力多了。\n", me);

	if( me->is_fighting() )
		me->start_busy(1);

	return 1;
}
