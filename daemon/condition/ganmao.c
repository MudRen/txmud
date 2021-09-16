// ganmao.c
// by Find.
// 天气不好的时候着凉感冒.

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration <= 1 )
	{
		tell_object(me,"你的感冒总算好了。\n");
		return CND_STOP;
	}

	if( me->query("eff_gin") >= me->query("max_gin")/2)
        	me->receive_wound("gin", 5,"illness");
        else
		me->receive_damage("gin",5,"illness");

        if( me->query("eff_sen") >= me->query("max_sen")*3/4)
        	me->receive_wound("sen", 10,"illness");
        else
                me->receive_damage("sen",10,"illness");

	message_vision(HIW "$N打了个喷嚏，看样子是感冒又发作了！\n" NOR , me);

	return CND_CONTINUE;
}
