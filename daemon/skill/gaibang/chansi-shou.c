// gaibang chansi-shou.c 缠丝擒拿手
// edit pian

#include <ansi.h>
inherit SKILL;
mapping *action = ({
	
([     "action":           HIG"$N双手如钩，正是缠丝擒拿手的第一式"+WHT"「饮马渡秋水」"+HIG"击向$n的$l。"NOR,
              "dodge":             -30,
              "parry":             -70,
              "force":             90,
              "damage_type":       "抓伤"
       ]),
([     "action":            HIG"$N身随意转，返手一掌"+WHT"「水寒风似刀」"+HIG"袭向$n的$l。"NOR,
              "dodge":             -10,
              "parry":             -60,
              "force":             160,
              "damage_type":       "瘀伤"
       ]),
([     "action":            HIG"$N右手一抄，左手如电，正是一招"+WHT"「平沙日未没」"+HIG"抓向$n的$l。"NOR,
              "dodge":             -30,
              "parry":             -40,
              "force":             190,
              "damage_type":       "瘀伤"
       ]),

([     "action":            HIG"$N撮指如锥，一招"+WHT"「黯黯见临洮」"+HIG"点向$n的$l。"NOR,
              "dodge":             -20,
              "parry":             -50,
              "force":             120,
              "damage_type":       "瘀伤"
       ]),

([     "action":            HIG"$N一式"+WHT"「昔日长城战」"+HIG"凌空跃起对准$n的$l抓了下去。"NOR,
              "dodge":             -70,
              "parry":             -40,
              "force":             140,
              "damage_type":       "瘀伤"
       ]),

([     "action":            HIG"$N又目如电，一声暴喝，一招"+WHT"「咸言意气高」"+HIG"带着破空之声袭向$n的$l。"NOR,
              "parry":             -90,
              "force":             140,
              "damage_type":       "瘀伤"
       ]),

([     "action":            HIG"$N右手递个虚招，左手一式"+WHT"「黄尘足古今」"+HIG"叼向$n的$l。"NOR,
              "parry":             -90,
              "force":             130,
              "damage_type":       "瘀伤"
       ]),

([     "action":            HIG"$N双目圆睁，使出[缠丝擒拿手]最后一式"+WHT"「白骨乱蓬蒿」"+HIG"袭向$n的$l。"NOR,
              "parry":             -90,
              "force":             220,
              "damage_type":       "瘀伤"
       ]),

});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail(HIY"\n你须要空手运用才能领悟『缠丝擒拿手』。\n"NOR);

	if( (int)me->query("max_force") < 200 )
		return notify_fail(HIY"你的内力太弱无法演练『缠丝擒拿手』。\n"NOR);
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
       return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("你的体力不够，不足以练习『缠丝擒拿手』。\n");
	if( (int)me->query("force") < 100 )
		return notify_fail("你的内力不够，不能练习『缠丝擒拿手』。\n");

	me->receive_damage("kee", 25, "tire");
	me->add("force", -3);
	return 1;
}

int effective_level() { return 14; }

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 80 )
		return 0;

	if( random(damage_bonus/2) > victim->query("str") )
	{
		victim->receive_wound("kee", (damage_bonus - 50) / 3 );

		switch(random(5))
		{
			case 0: return "你听到「喀啦」一声轻响竟似是骨碎的声音。\n";
			case 1: return "$N劲力一吐$n的$l发出「喀」地一声爆响。\n";
			case 2: return "只听见$n的$l「喀」地一声 ...\n";
			case 3: return "$N的双手如同一条活鱼一样，迅捷无伦地击中$n的$l！\n";
			case 4: return "[缠丝擒拿手]手果然名不虚传，$n的$l立刻被印上一记！\n";
		}
	}
}

string *parry_msg = ({
	HIG"$n一招「白骨乱蓬蒿」，双手交互攻向$N的$w。\n"NOR,
	HIG"$n使出一招「黄尘足古今」，瞬间攻出数招，却避开了$N的攻势。\n"NOR,
	HIG"$n身体向后一掠，一式「饮马渡秋水」，避开了$N的攻势。\n"NOR,
});

string *unarmed_parry_msg = ({
	"$n使出一招「乱云穿空」，双手瞬间攻出数招，避开了$N的攻势。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("gaibang") + "/chansi-shou/" + action;
}