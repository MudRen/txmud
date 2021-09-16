// jiaohua-stick 叫化棍法

inherit SKILL;
mapping *action = ({
([  "action": "$N往左边一晃，似要横棍扫来，$w却直直地向$n的$l戳去",
        "dodge": 0,
        "force": 40,
        "damage_type": "刺伤"
]),
([  "action": "$N大喝一声，手中$w劈头盖脸地就往$n抡去",
        "dodge": 0,
        "force": 50,
        "damage_type": "淤伤"
]),

([  "action": "$N手臂青筋暴起，抡着$w狠命地向着$n的$l扫去",
        "dodge": 0,
        "force": 50,
        "damage_type": "淤伤"
]),

});


int valid_enable(string usage) { return (usage == "stick") || (usage == "parry"); }

int effective_level() { return 10;}

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够雄厚，无法学习叫化棍法。\n");
        if ((int)me->query_skill("stick", 1) < 50)
                return notify_fail("你的基础棍法不够熟练，无法学习叫化棍法。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "stick")
                return notify_fail("你应该首先装备棍子作为武器。\n");
        if( (int)me->query("kee") < 30 || (int)me->query("force") < 30 )
                return notify_fail("你目前身体状况太差，无法练习叫化棍法。\n");
        me->receive_damage("kee", 10, "tire");
        me->add("force", -10);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("gaibang") + "/jiaohua-stick/" + action;
}

string *parry_msg = ({
        "$n把手中的$v舞的是风雨不透，封住了$N的攻势。\n",
});
string *unarmed_parry_msg = ({
        "$n把手中的$v舞的是风雨不透，封住了$N的攻势。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

