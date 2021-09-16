// wugong_poison.c

#include <condition.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_prevent_poison_eff())
	{
		tell_object(me, "��������򼶾�ķ������ӻ��ˡ�\n");
		return CND_NO_CHANGE;
	}

	me->receive_wound("kee", 15,"poison");
	me->receive_wound("kee", 25,"poison");

	me->receive_damage("sen", 10,"poison");

	if( duration <= 1 )
		tell_object(me, HIR "���е���򼶾���ڷ������ˣ�\n" NOR );
	else
		tell_object(me, HIR "���е���򼶾�����ˣ�ֻ���û���ʹ�����̣�ͷ�������ġ�\n" NOR );

	return CND_CONTINUE;
}
