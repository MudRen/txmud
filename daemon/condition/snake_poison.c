// snake_poison.c

#include <condition.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_prevent_poison_eff())
	{
		tell_object(me, "�������߶��ķ������ӻ��ˡ�\n");
		return CND_NO_CHANGE;
	}

	me->receive_wound("kee", 7,"poison");
	me->receive_damage("sen", 10,"poison");

	if( duration <= 1 )
		tell_object(me, HIG "���е��߶����ڷ������ˣ�\n" NOR );
	else
		tell_object(me, HIG "���е��߶������ˣ�\n" NOR );

	return CND_CONTINUE;
}
