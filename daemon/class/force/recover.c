// recover.c

inherit SSERVER;

int exert(object me, object target)
{
	int diff, neilineed;
	int eff,now,ef,f;

	if( target != me )
		return notify_fail("你只能用内功调匀自己的气息。\n");

	if( (f = (int)me->query("force")) < 20 )
		return notify_fail("你的内力不够。\n");
	if( (ef = (int)me->query_skill("force")) < 10 )
		return notify_fail("你的内功修为不够。\n");	

	eff = me->query("eff_kee");
	now = me->query("kee");

	diff = eff - now;

	if(diff < 1)
		return notify_fail("你现在气血充盈，不需要行功运气补充。\n");

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

	me->receive_heal("kee", diff);
	me->add("force", -neilineed);

	message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);

	if( me->is_fighting() )
		me->start_busy(1);

	return 1;
}
