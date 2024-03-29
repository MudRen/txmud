// cibei-blade.c 慈悲刀
// 特攻：我佛慈悲 cibei (带动人的身形使 busy)

inherit SKILL;

mapping *action = ({
([      "action" : "$N身体向下一伏，手中$w斜指，一招「矮人观场」，一刀向$n的$l攻去",
        "force" : 120,
        "dodge" : -10,
        "damage_type" : "割伤"
]),
([      "action" : "$N一式「悲天悯人」，手中$w倒转，用刀背拍向$n的$l。",
        "dodge" : -10,
        "damage" : 45,
        "damage_type" : "淤伤"
]),
([      "action" : "$N身形一闪，手中$w疾抖，一招「曾经沧海」，罩向$n的$l",
        "damage" : 45,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「开门见山」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
        "damage" : 25,
        "damage_type" : "割伤"
]),
([      "action" : "$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全身涌去",
        "force" : 180,
        "dodge" : 20,
        "damage" : 60,
        "damage_type" : "割伤"
]),
});

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你必须先找一把刀，才能学习慈悲刀。\n");

	if(me->query_skill("cibei-blade",1) >= me->query_skill("dacheng-fofa",1)
	|| (int)me->query_skill("dacheng-fofa", 1) < 30)
		return notify_fail("你的大成佛法修为不够，无法修习慈悲刀。\n");
	return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;
	if( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade" )
		return notify_fail("你必须先找一把刀，才能练习慈悲刀。\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不支，还是先休息休息吧。\n");
	me->receive_damage("kee", 40,"tire");
	return 1;       
}

int effective_level() { return 10;}

string *parry_msg = ({
	"$n左手一晃，用手中的$v急削$N的五指，化解了$N的攻势。\n",
	"$n不退反进，手中的$v直劈$N握$w的双手，化解了$N的攻势。\n",
});

string *unarmed_parry_msg = ({
	"$n左手一晃，用手中的$v急削$N的五指，化解了$N的攻势。\n",
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
	return -30;
}
int practice_bonus()
{
	return -50;
}

int black_white_ness()
{
        return -20;
}

string perform_action_file(string action)
{
	return CLASS_D("shaolin") + "/cibei-blade/" + action;
}
