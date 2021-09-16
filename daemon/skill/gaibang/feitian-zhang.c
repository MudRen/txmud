// 飞天杖法
// by dicky

inherit SKILL;
mapping *action = ({
([  "action": "$N杖法突变，杖势伸缩不定，奔腾矫夭，斜肩铲背砸向$n的$l",
        "dodge": -8,
        "force": 50,
        "damage_type": "刺伤"
]),
([  "action": "$N一声大喝使出「夺魄催心」, 手中$w幻出满天杖影自下而上扫向$n的$l",
        "dodge": -5,
        "force": 60,
	"damage_type": "刺伤"
]),

([  "action": "只见$N不退反进，身如飘风，诡异地将$w从肩头发出砸向往$n的$l",
        "dodge": -5,
        "force": 70,
        "damage_type": "淤伤"
]),

([  "action": "$N以攻为守，以进为退， $w从手中掷出，飞向$n的$l",
        "dodge": -10,
        "force": 80,
        "damage_type": "淤伤"
]),
});


int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int effective_level() { return 12;}

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("gaibang-force", 1) < 30)
                return notify_fail("你的丐帮心法学习得还不够。\n");
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
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("kee") < 30 || (int)me->query("force") < 15 )
                return notify_fail("你的内力或气不够，没有办法练习飞天杖法。\n");
        me->receive_damage("kee", 30, "tire");
        me->add("force", -15);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("gaibang") + "/feitian-zhang/" + action;
}

string *parry_msg = ({
	"$n把手中$v幻花作一层气墙，阻挡住了$N的$w。\n",
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