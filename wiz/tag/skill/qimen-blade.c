// qimen-blade
// by dicky

inherit SKILL;

mapping *action = ({
([      "action" : "$N一声长啸，手中$w一扬，无数刀尖化作点点繁星，向$n的$l挑去",
        "dodge" : 5,
        "force": 50,
        "damage_type" : "割伤"
]),
([      "action" : "$N大喝一声「看招」，一招「劈天盖地满壮志」，刀锋自上而下向$n的$l挥去",
        "dodge" : 10,
        "force": 60,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「弯刀逆转倒乾坤」，手中$w在空中急速转动数圈，划向$n的$l",
        "dodge" : 0,
        "force": 70,
        "damage_type" : "割伤",
]),
([      "action" : "$N神色肃杀，一声虎吼，掌中刀光闪烁不定，一片刺骨的刀风将$n团团围住!",
        "dodge" : 10,
        "force": 80,
        "damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

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
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("kee") < 30 || (int)me->query("force") < 15 )
                return notify_fail("你的内力或气不够，没有办法练习奇门刀法。\n");
        me->receive_damage("kee", 30, "tire");
        me->add("force", -15);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("gaibang") + "/qimen-blade/" + action;
}

string *parry_msg = ({
	"$n把手中$v幻花作剑墙，阻挡住了$N的$w。\n",
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