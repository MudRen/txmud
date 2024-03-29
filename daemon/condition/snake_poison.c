// snake_poison.c

#include <condition.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_prevent_poison_eff())
	{
		tell_object(me, "你体内蛇毒的发作被延缓了。\n");
		return CND_NO_CHANGE;
	}

	me->receive_wound("kee", 7,"poison");
	me->receive_damage("sen", 10,"poison");

	if( duration <= 1 )
		tell_object(me, HIG "你中的蛇毒终于发作光了！\n" NOR );
	else
		tell_object(me, HIG "你中的蛇毒发作了！\n" NOR );

	return CND_CONTINUE;
}
