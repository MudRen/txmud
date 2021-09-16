// drunk.c

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit = 50, kee = me->query("kee");

	if( limit >= kee ) {
		me->unconcious();
		return CND_STOP;
	} else if( !living(me) ) {
		message_vision("$N���˸�����������Ȼ�������ࡣ\n", me);
	} else if( kee >= limit*4 ) {
		tell_object(me, "�����һ������ϳ壬��Ƥ��Щ�����ˡ�\n");
		message_vision( "$N�����Ѿ����Ծ����ˡ�\n", me);
		me->receive_damage("sen", 10);
	} else if( kee >= limit*2 ) {
		tell_object(me, "��������л�������������ƮƮ�أ���������ˡ�\n");
		message_vision("$Nҡͷ���Ե�վ��վ���ȣ���Ȼ�Ǻ����ˡ�\n", me);
		me->receive_damage("sen", 3);
		me->receive_damage("gin", 10);
		me->receive_damage("kee", 15);
	}

	return CND_CONTINUE;
}
