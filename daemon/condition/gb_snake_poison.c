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
		message_vision(BLU "$N两眼发直，身子瑟瑟抖了起来！\n" NOR, me);
	else
		message_vision(BLU "$N痛苦地呻咛了一声！\n" NOR, me);

	if(!me->is_busy()) me->start_busy(1);

	if( duration < 1 )
	{
		message_vision(HIB "$N突然痛苦地剧烈挣扎，脸部变得浮肿，皮肤象火一样烧了起来！\n" NOR, me);
		return 0;
	}
	return 1;
}
