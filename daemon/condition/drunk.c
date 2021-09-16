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
		message_vision("$N打了个隔，不过依然烂醉如泥。\n", me);
	} else if( kee >= limit*4 ) {
		tell_object(me, "你觉得一阵酒意上冲，眼皮有些沉重了。\n");
		message_vision( "$N脸上已经略显酒意了。\n", me);
		me->receive_damage("sen", 10);
	} else if( kee >= limit*2 ) {
		tell_object(me, "你觉得脑中昏昏沉沉，身子轻飘飘地，大概是醉了。\n");
		message_vision("$N摇头晃脑地站都站不稳，显然是喝醉了。\n", me);
		me->receive_damage("sen", 3);
		me->receive_damage("gin", 10);
		me->receive_damage("kee", 15);
	}

	return CND_CONTINUE;
}
