// he_ding_hong.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	me->receive_wound("gin", 25,"poison");
	me->receive_wound("kee", 30,"poison");
	me->receive_wound("sen", 20,"poison");

	tell_object(me, HIG "���е�"+HIR+"�׶���"+HIG+"�������ˣ�\n" NOR );

	message_vision("$N��ɫ���࣬����������Ѫ��\n", me);

	return CND_CONTINUE;
}
