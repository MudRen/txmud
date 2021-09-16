// lianhuan-sword.c 连环剑

inherit SKILL;

mapping *action = ({
([      "action":"$N手中$w嗡嗡微振，一招「前后有秩」，刺向$n的$l",
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "刺伤"
]),

([      "action":"$N错步上前，使出「腾云驾雾」，剑意若有若无，$w罩向$n的$l",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "割伤"
]),
([      "action":"$N一式「螳螂捕蝉」，身形忽左忽右，手中$w向$n罩去",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w中宫直进，一式「不死不休」，无声无息地对准$n的$l刺出一剑",
        "dodge" : 35,
        "damage": 160,
        "damage_type":  "刺伤"
]),

});

int valid_learn(object me)
{
	return 0;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
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
