// mabi.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	tell_object(me, HIB"\n��ֻ��������һ����ľ����֫���������ˡ�\n\n"NOR);

	me->start_busy(2);

	return CND_CONTINUE;
}
