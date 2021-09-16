// tangdu.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if(me->query_prevent_poison_eff())
	{
		tell_object(me, "������������Ӱ���ķ������ӻ��ˡ�\n");
		return CND_NO_CHANGE;
	}

	me->receive_wound("gin", 20,"poison");
	me->receive_wound("kee", 30,"poison");
	me->receive_wound("sen", 20,"poison");

	tell_object(me, HIB "������һ�������������Ӱ�������ˣ�\n" NOR );
	message_vision( "$N���ؽ�������ɫ�԰ף�ʹ���������һ����\n", me);

	return CND_CONTINUE;
}
