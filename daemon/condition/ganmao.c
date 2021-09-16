// ganmao.c
// by Find.
// �������õ�ʱ��������ð.

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration <= 1 )
	{
		tell_object(me,"��ĸ�ð������ˡ�\n");
		return CND_STOP;
	}

	if( me->query("eff_gin") >= me->query("max_gin")/2)
        	me->receive_wound("gin", 5,"illness");
        else
		me->receive_damage("gin",5,"illness");

        if( me->query("eff_sen") >= me->query("max_sen")*3/4)
        	me->receive_wound("sen", 10,"illness");
        else
                me->receive_damage("sen",10,"illness");

	message_vision(HIW "$N���˸����磬�������Ǹ�ð�ַ����ˣ�\n" NOR , me);

	return CND_CONTINUE;
}
