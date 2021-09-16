// gaibang taizu-changquan.c 太祖长拳
// edit pian

#include <ansi.h>
inherit SKILL;
mapping *action = ({
	
([     "action":           HIG"$N双拳一前一后，正是一招"+WHT"「天地元黄」"+HIG"击向$n的$l．"NOR,
              "dodge":             -30,
              "parry":             -70,
              "force":             90,
              "damage_type":       "抓伤"
       ]),
([     "action":            HIG"$N身影一转，双手一送"+WHT"「宇宙洪荒」"+HIG"直击$n$l．"NOR,
              "dodge":             -10,
              "parry":             -60,
              "force":             160,
              "damage_type":       "瘀伤"
       ]),
([     "action":            HIG"$N右手一圈，正是一招"+WHT"「秋收冬藏」"+HIG"拍向$n的$l．"NOR,
              "dodge":             -30,
              "parry":             -40,
              "force":             90,
              "damage_type":       "瘀伤"
       ]),

([     "action":            HIG"$N双手一抖，一式"+WHT"「辰宿列张」"+HIG"对准$n的$l抓去．"NOR,
              "dodge":             10,
              "parry":             -60,
              "force":             120,
              "damage_type":       "抓伤"
       ]),

([     "action":            HIG"$N左手虚晃右掌飘飘一招"+WHT"「寒来暑往」"+HIG"击向$n$l．"NOR,
              "dodge":             -20,
              "parry":             -50,
              "force":             90,
              "damage_type":       "瘀伤"
       ]),

([     "action":            HIG"$N使出"+WHT"「云腾致雨」"+HIG"凌空跃起对准$n$l拍出一掌．"NOR,
              "dodge":             -70,
              "parry":             -40,
              "force":             110,
              "damage_type":       "瘀伤"
       ]),

([     "action":            HIG"$N右手在$n$l划过随後一招"+WHT"「露结为霜」"+HIG"左手又已抓到．"NOR,
              "parry":             -90,
              "force":             130,
              "damage_type":       "瘀伤"
       ]),

([     "action":            HIG"$N右手递个虚招，左手使出"+WHT"「举火燎天」"+HIG"击向$n的$l．"NOR,
              "parry":             -90,
              "force":             100,
              "damage_type":       "瘀伤"
       ]),

});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("\n你须要空手运用才能领悟『太祖长拳』。\n"NOR);

	if( (int)me->query("max_force") < 20 )
		return notify_fail(HIY"你的内力太弱无法演练『太祖长拳』。\n"NOR);
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
		return notify_fail("你的体力不够，不足以练习『太祖长拳』。\n");
	if( (int)me->query("force") < 100 )
		return notify_fail("你的内力不够，不能练习『太祖长拳』。\n");

	me->receive_damage("kee", 25, "tire");
	me->add("force", -3);
	return 1;
}

int effective_level() { return 10; }

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
			case 4: return "华山拂云手果然名不虚传，$n的$l立刻被印上一记！\n";
		}
	}
}

string *parry_msg = ({
	"$n一招「西出阳关」，双手交互攻向$N的$w。\n",
	"$n使出一招「逐红叶」，双手瞬间攻出数招，避推了$N的攻势。\n",
});

string *unarmed_parry_msg = ({
	"$n使出一招「山山红遍」，双手瞬间攻出数招，避推了$N的攻势。\n",
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
