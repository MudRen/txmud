// weapon_bleeding.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	me->receive_damage("kee", 10);
	tell_object(me, HIR "�����ϵ��˿�Ѫ����ֹ��\n" NOR );

	return CND_CONTINUE;
}
