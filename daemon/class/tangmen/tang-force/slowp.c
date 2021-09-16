// slowp.c
// 延迟一次毒的发作。

int exert(object me, object target)
{
	if(me->query_skill("tang-force", 1) < 150)
		return notify_fail("你的内功修为不够，无法克制毒素。\n");

	if( me->query("max_force") < 200 )
		return notify_fail("你的内功修为不够，无法克制毒素。\n");

	if( me->query("force") < 300 )
		return notify_fail("你体内的真气不够，无法克制毒的发作。\n");

	me->add("force",-300);
	tell_object(me, "你行功一周天，暂时延缓了体内的血液流动。\n");
	if(me->is_fighting())
		me->start_busy(2);
	return 1;
}
