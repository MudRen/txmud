// wugong_poison.c

#include <condition.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_prevent_poison_eff())
	{
		tell_object(me, "你体内蜈蚣毒的发作被延缓了。\n");
		return CND_NO_CHANGE;
	}

	me->receive_wound("kee", 15,"poison");
	me->receive_wound("kee", 25,"poison");

	me->receive_damage("sen", 10,"poison");

	if( duration <= 1 )
		tell_object(me, HIR "你中的蜈蚣毒终于发作光了！\n" NOR );
	else
		tell_object(me, HIR "你中的蜈蚣毒发作了！只觉得浑身痛痒难忍，头昏昏沉沉的。\n" NOR );

	return CND_CONTINUE;
}
