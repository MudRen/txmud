// lianhuan-chui.c 连环锤法

inherit SKILL;

mapping *action = ({
([      "action":"$N手中$w一碰，“当”的一声大响，一招「金钟齐鸣」，砸向$n的$l",
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "挫伤",
]),

([      "action":"$N错步上前，手中$w轮圆了照着$n的$l砸了下去",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "挫伤",
]),
([      "action":"$N一式「泰山压顶」，手中$w由上至下向$n砸了下来",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "挫伤",
]),

});

int valid_learn(object me)
{
	return 0;
}

int valid_enable(string usage)
{
	return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	return 0;
}

int effective_level() { return 12;}

string *parry_msg = ({
	"结果$n用手中的$v格开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
	"$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
	return CLASS_D("npc_skill") + "/lianhuan-sword/" + action;
}
