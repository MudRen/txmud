// yi.c
// 移行幻影 yi
// 天蝉步法[tianchan-steps] 的特攻

#include <ansi.h>
#include <combat.h>

int perform(object me, object target)
{
	int skill,mp,tp, n, i, nub;
	object env, *enemy;
	mapping exits;
	string *dirs = ({});

	if(me->is_busy())
		return notify_fail("你上一个动作没有完成，无法使用『我佛慈悲』。\n");

	if((skill = me->query_skill("tianchan-steps",1)) < 180)
		return notify_fail("你的『天蝉步法』功力不足，没法移行幻影。\n");

	if(!n = sizeof(enemy = me->query_enemy()))
		return notify_fail("『移行幻影』是在战斗中使用的技能。\n");

	if( me->query("force") < 100 )
		return notify_fail("你的真气不足，无法施展『移行幻影』。\n");

	if(!(env = environment(me)) || !sizeof(exits = env->query("exits")) )
		return notify_fail("此地无法施展『移行幻影』。\n");

	foreach(string dir, string file in exits)
	{
		if(env->valid_leave(me, dir))
			dirs += ({ file });
	}

	if(!sizeof(dirs))
		return notify_fail("此地无法施展『移行幻影』。\n");

	me->add("force",-100);

	message_vision(HIB"\n$N身行急转，脚尖点地一猫腰，施展出『移行幻影』。\n", me);

	mp = COMBAT_D->skill_power(me,"dodge",SKILL_USAGE_DEFENSE);

	if(n>4)
		n=4;
	for(i=0; i<n; i++)
	{
		int tmp;
		if( tp < (tmp = COMBAT_D->skill_power(enemy[i],"dodge",SKILL_USAGE_DEFENSE)) )
		{
			tp = tmp;
			nub = i;
		}
	}

	if(mp >= random(tp*0.6))	// 成功
	{
		if(!me->move(dirs[random(sizeof(dirs))]))
			return notify_fail("此地点有错误，请立刻通知管理员处理。\n");
		tell_room(env, sprintf("你只觉得眼前人影一晃，失去了%s的踪影。\n", me->name()));
		me->start_busy(1);
		return 1;
	}

	message_vision("$N看破了$n的意图，一晃身挡住了$n的退路。\n", enemy[nub], me);
	me->start_busy(2);

	me->start_perform_busy(12);
	return 1;
}
