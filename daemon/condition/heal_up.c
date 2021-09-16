// heal_up.c
// 疗伤的 condition.
// by Find.

#include <condition.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	int max_gin,max_kee,max_sen;

	max_gin = me->query("max_gin");
	max_kee = me->query("max_kee");
	max_sen = me->query("max_sen");

	if(me->query("eff_gin") == max_gin
	&& me->query("eff_kee") == max_kee
	&& me->query("eff_sen") == max_sen)
	{
		tell_object(me,HIG+"你的伤口痊愈了，身体恢复了正常。\n"+NOR);
		return CND_STOP;
	}

	me->receive_curing("gin",max_gin/20);
	me->receive_curing("kee",max_kee/20);
	me->receive_curing("sen",max_sen/20);

	if(me->query("eff_gin") == max_gin
	&& me->query("eff_kee") == max_kee
	&& me->query("eff_sen") == max_sen)
	{
		tell_object(me,HIG+"你的伤口痊愈了，身体恢复了正常。\n"+NOR);
		return CND_STOP;
	}

	return CND_CONTINUE;
}