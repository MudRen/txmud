// mabi.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	tell_object(me, HIB"\n你只觉得身上一阵麻木，四肢都动不了了。\n\n"NOR);

	me->start_busy(2);

	return CND_CONTINUE;
}
