// si.c 你死我活
// longjiao-blade 的特攻

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill, damage,count,temp,ap,dp;
	mapping my;
	object weapon;

	if(!me->query("family/valid_perform_si"))
		return 0;

	if(!weapon = me->query_temp("weapon"))
		return notify_fail("你无法施展『你死我活』\n");

	if( !target )
		target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
                return notify_fail("『你死我活』只能对战斗中的对手使用。\n");

	if( ( skill = (int)me->query_skill("longjiao-blade",1)) < 150)
		return notify_fail("你的『缚龙斩鲛刀法』功力不足，无法使用『你死我活』。\n");

	if( (int)me->query("force")< 800 )
		return notify_fail("你的内力不够，无法使用『你死我活』。\n");

	my = me->query_entire_dbase();
	if( (my["kee"] <= my["max_kee"]/2)
	|| (my["eff_kee"] <= my["max_kee"]/2)
	|| (my["gin"] <= my["max_gin"]/2)
	|| (my["eff_gin"] <= my["max_gin"]/2)
	|| (my["sen"] <= my["max_sen"]/2)
	|| (my["eff_sen"] <= my["max_sen"]/2) )
		return notify_fail("你目前身体状况不好，如果强自提升功力后果不堪设想。\n");

	damage = my["kee"];
	if(my["eff_kee"] < damage)
		damage = my["eff_kee"];
	if(my["gin"] < damage)
		damage = my["gin"];
	if(my["eff_gin"] < damage)
		damage = my["eff_gin"];
	if(my["sen"] < damage)
		damage = my["sen"];
	if(my["eff_sen"] < damage)
		damage = my["eff_sen"];

	damage = damage*70/100;

	// 最少内力 500，每加一个等级再需要100点内力
	count = (skill-150)/50;
	temp = (my["force"] - 500)/100;
	if(count < temp)
		count = temp;
	if(count > 7)
		count = 7;

	message_vision(sprintf(HIR"\n$N双目尽赤，嘴角淌出一丝鲜血，突然大吼一声，太阳穴高鼓，\n手中%s%s迅捷无比地向$n%s砍去！！\n\n"NOR,
		weapon->name(),HIR,HIR), me, target);

	// 必须先取攻防
	ap = COMBAT_D->skill_power(me,"blade",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE)/4;

	me->receive_damage("kee",damage,"tire");
	me->receive_wound("kee",damage,"tire");
	me->receive_damage("gin",damage,"tire");
	me->receive_wound("gin",damage,"tire");
	me->receive_damage("sen",damage,"tire");
	me->receive_wound("sen",damage,"tire");

	me->add("max_force",-(50+count*10));
	me->set_status_xuruo(10);
	me->start_busy(1);

	if(random(ap + dp) < dp)	// 失败
	{
		object env,out;
		mapping exits;
		int flag;
		string dir;

		if(!objectp(env = environment(me)) || !env->is_room())
			return 1;

		if(!mapp(exits = env->query("exits")) || !sizeof(exits))
			flag = 1;

		foreach(string ex,string file in exits)
		{
			if(!objectp(out = find_object(file)))
				out = load_object(file);
			if(!out)
				continue;
			else
			{
				dir = to_chinese(ex);
				break;
			}
		}

		if(!out || flag)
		{
			message_vision("$N极力躲闪，总算堪堪躲过了$n这一招，但人也被吓得骨软筋麻。\n",target,me);
			target->start_busy(3);
			return 1;
		}

		message_vision(sprintf("$N被$n这种拼命招法所震慑，吓得扭头就跑。。。。。。\n$N向方向落荒而逃。\n\n",dir),
			target, me);
		target->move(out);
		tell_room(out,sprintf("%s跌跌撞撞的跑了过来，脸色煞白。\n",target->name()),({target}));
		target->start_busy(1);
		return 1;
	}

	message_vision(sprintf(HIB"\n$N被%s击中，发出一声痛苦的惨号。。。\n"NOR,weapon->name()),target);

	damage = damage*count*15/100;
	target->start_busy(4);
	target->receive_damage("kee",damage,me);
	target->receive_wound("kee",damage,me);
	target->receive_damage("gin",damage,me);
	target->receive_wound("gin",damage,me);
	target->receive_damage("sen",damage,me);
	target->receive_wound("sen",damage,me);
	COMBAT_D->report_status(target);

	me->start_perform_busy(15);
	return 1;
}
