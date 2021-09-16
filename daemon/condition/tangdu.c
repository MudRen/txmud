// tangdu.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if(me->query_prevent_poison_eff())
	{
		tell_object(me, "你体内唐门无影毒的发作被延缓了。\n");
		return CND_NO_CHANGE;
	}

	me->receive_wound("gin", 20,"poison");
	me->receive_wound("kee", 30,"poison");
	me->receive_wound("sen", 20,"poison");

	tell_object(me, HIB "你身体一阵紧缩，唐门无影毒发作了！\n" NOR );
	message_vision( "$N牙关紧锁，脸色苍白，痛苦的呻吟了一声！\n", me);

	return CND_CONTINUE;
}
