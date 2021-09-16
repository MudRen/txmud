// pofeng_blade.c

inherit SKILL;
mapping *action = ({
        ([      "action":               "$N使一招「要你小命」，手中$w风似地向$n的$l斩去！",
                "damage":               180,
                "dodge":                70,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N弯刀似月，$w随著一招「不死即伤」由下而上撩往$n的$l",
                "damage":               160,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N身形一转，一招「和你拼了」$w如狂风暴雨撒向$n的$l",
                "damage":               140,
                "damage_type":  "割伤"
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
        "$n使出一招「七零八落」，用手中的$v急削$N的五指。\n",
        "$n手中的$v一抖，挽出一片刀花，狂风暴雨般撒向$N的全身。\n",
        "$n微退一步，手中的$v划出一条光弧，将$N的全身围住。\n",
});

string *unarmed_parry_msg = ({
"$n使出一招「要你小命」，用手中的$v急砍$N。\n",
"$n左脚踏前踏，手中的$v直劈向$N之必救。\n",
"$n手中的$v划出一招「风雨不透」，将$N的全身围住。\n",
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
        return 40;
}

int practice_bonus()
{
return 5;
}

int black_white_ness()
{
        return 20;
}