// lianhuan-blade.c
// 连环刀。(巡捕专用)

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w斜指，一招「停车问路」，反身一顿，一刀向$n的$l撩去",
        "force" : 120,
        "dodge" : -10,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「童子拜佛」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
        "dodge" : -10,
        "damage" : 45,
        "damage_type" : "割伤"
]),
([      "action" : "$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
        "damage" : 45,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「开门见山」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
        "damage" : 25,
        "damage_type" : "割伤"
]),

});

int valid_learn(object me)
{
	return 0;
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
	return 0;
}

int effective_level() { return 15;}

string *parry_msg = ({
        "$n左手一晃，用手中的$v急削$N的五指。\n",
        "$n不退反进，手中的$v直劈$N握$w的双手。\n",
});

string *unarmed_parry_msg = ({
        "$n左手一晃，用手中的$v急削$N的五指。\n",
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
	return CLASS_D("npc_skill") + "/lianhuan-blade/" + action;
}
