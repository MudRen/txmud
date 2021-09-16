// gb_snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("gin", 40);
	me->receive_damage("gin", 40);
	me->receive_wound("kee", 60);
	me->receive_damage("kee", 60,"poison");

	me->apply_condition("gb_snake_poison", duration - 1);

	if (living(me))
		message_vision(BLU "$N���۷�ֱ������ɪɪ����������\n" NOR, me);
	else
		message_vision(BLU "$Nʹ���������һ����\n" NOR, me);

	if(!me->is_busy()) me->start_busy(1);

	if( duration < 1 )
	{
		message_vision(HIB "$NͻȻʹ��ؾ���������������ø��ף�Ƥ�����һ������������\n" NOR, me);
		return 0;
	}
	return 1;
}
