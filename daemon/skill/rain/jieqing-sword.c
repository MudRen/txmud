// jieqing-sword.c
// 戒情剑法

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N一招「黯然神伤」，顿时手中$w疾如飘风，迅如闪电般刺向n的$l",
                "dodge":                -10,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出的「伤心欲绝」，手中的$w划出一道森冷寒光劈向$n的$l",
                "dodge":                10,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出「绝情断义」，一道剑光，带着一团劲风，笔直疾袭$n的$l",
                "dodge":                -10,
                "damage":               80,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w以一式「心如止水」一练数招，有如疾风迅雨，雷霆乍发般刺向$n的$l。",
                "dodge":                40,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"只见剑气纵横，寒光腾霄，$N一招「心死缘灭」自半空对着$n连刺数剑",
                "dodge":                30,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一式「落发戒情」，手中的$w如冰山下塌，银河倒泻，挟着隐隐风雷之声刺向$n的$l",
                "dodge":                60,
                "damage":               110,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"满空剑光忽敛，$N一式「长伴青灯」，手中的$w化为一道奇短奇亮的精光，刺向$n的$l",
                "dodge":                30,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一招「了此残生」，身剑合一，化为一道寒光，刺向$n的$l",
                "dodge":                -30,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 20 )
                return notify_fail("你的内力不够，没有办法练『戒情剑法』。\n");

        if( (string)me->query_skill_mapped("force") != "suiyu-force")
                return notify_fail("『戒情剑法』必须配合『随雨无风心法』才能练。\n");

        if( !(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

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
	if( (me->query("kee") < 30)
	|| (me->query("force") < 5) )
		return notify_fail("你的内力或气不够，没有办法练习『戒情剑法』。\n");
	me->receive_damage("kee", 30, "tire");
        me->add("force", -5);
        write("你按著所学练了一遍『戒情剑法』。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("rain") + "/jieqing-sword/" + action;
}
 
int effective_level() { return 12;}

string *parry_msg = ({
        "$n使出一招「天地同泣」，手中的$v化作一道剑幕，封住了$N的$w。\n",
        "$n使出「心似冰冻」，手中的$v将$N的$w一一点开。\n",
        "$n使出一招「生无可恋」，手中的$v有如毒蛇般缠住了$N的$w。\n",
        "$n手中的$v斜斜划出，一招「斩情断缘」，向$N的$w的劈去。\n",
});

string *unarmed_parry_msg = ({
        "$n手中的$v中宫直刺，使得$N的回招自保。\n",
        "$n一式「来生寻缘」，整个人忽然消失了。\n",
        "$n使出一招「既然无缘」，$v无情的缠向了$N的$w。\n",
        "$n以鬼魅般的剑气逼得$N连连后退。\n",
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
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 15;
}


