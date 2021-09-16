inherit SKILL;

mapping *action = ({
([      "action":"$N手中$w微微轻振，向前递出，一招「醉歌舞月」，划向$n的$l",
        "dodge" : -10,
        "damage": 50,
        "damage_type":  "刺伤"
]),
([      "action":"$N错步上前，使出「长娥奔月」，剑意若有若无，$w罩向$n的$l",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "割伤"
]),
([      "action":"$N一式「月悄悄」，身形忽左忽右，剑式四处变换，手中$w向$n罩去",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "割伤"
]),
([      "action":"$N纵身轻轻跃起丈许，一式「月舞翩跹」，剑光闪过，自上而下斩向$n的$l",
        "dodge" : 10,
        "damage": 60,
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w画了个半圆，突然一式「空望月」，对准$n的$l连贯刺出数剑",
        "dodge" : 35,
        "damage": 70,
        "damage_type":  "刺伤"
]),
([      "action":"$N用「月光倾洒」出气走壬督，内力灌运于$w剑尖青光突现，剑气射向$n的$l",
        "dodge" : 60,
        "damage": 80,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，无法修习月光剑法。\n");
        if( ((int)me->query_skill("jinghai-force",1) <= 20 )
        || (me->query_skill("moonlight-sword",1) >= me->query_skill("jinghai-force",1)) )
                return notify_fail("你的靖海神功修为不够，无法修习月光剑法。\n");

        return 1;
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
        if( (int)me->query("kee") < 30 || (int)me->query("force") < 3 )
                return notify_fail("你的内力或气不够，没有办法练习月光剑法。\n");
        me->receive_damage("kee", 30, "tire");
        me->add("force", -3);
        write("你按著所学练了一遍月光剑法。\n");
        return 1;
}

int learn_bonus()
{
        return -20;
}

int practice_bonus()
{
        return -40;
}

int black_white_ness()
{
        return -10;
}

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
        return CLASS_D("jinghai") + "/moonlight-sword/" + action;
}

