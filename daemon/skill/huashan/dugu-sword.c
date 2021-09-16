// huashan dugu-sword.c

#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N剑走中宫，正是独孤九剑起手式「御剑三飞」，手中$w幻出三道剑芒。",
                "dodge":                -20,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N剑走偏锋，一招「离剑如钩」，手中的$w带着丝丝剑气脱手而出。",
                "dodge":                20,
                "damage":               60,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N身随剑转，一招「荡剑九霄」，身形暴起，手中$w化作漫天剑影向$n罩了下去。",
                "dodge":                30,
                "damage":               60,
                "damage_type":  "割伤"
        ]),
     ([      "action":               
"$N手中$w轻轻一摆，一式「破剑索喉」，对准$n迎出一剑",
                "dodge":                -40,
                "damage":		80,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N足尖点地身形再起，手中$w一招「剑冲九天」对准$n斜斜挑出一剑",
                "dodge":                -40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N气沉丹田以气御剑，一招「万剑归宗」，自$w中逼出无数道剑气袭向$n。",
                "dodge":                40,
                "damage":               80,
                "damage_type":  "刺伤"
        ]),
    });

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练独孤剑法。\n");

	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("练剑也得有把剑才行吧？\n");
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
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习独孤九剑。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍独孤剑法。\n");
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/dugu-sword/" + action;
}
 
int effective_level() { return 11;}
int effective_parry_level() { return 13; }

string *parry_msg = ({
        "$n使出一招「荡剑式」，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n使出「破剑式」，将$N的$w封于丈外。\n",
        "$n使出一招「万剑归宗」，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「心本无剑」，向$N拿$w的手腕削去。\n",
});
string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手一招「荡剑式」，整个人消失在一团剑光之中。\n",
        "$n使出一招「破剑式」，$v直刺$N的双手。\n",
        "$n将手中的$v化做七条剑气，迫得$N连连后退。\n",
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
        return -40;
}
int practice_bonus()
{
        return -70;
}
int black_white_ness()
{
        return 0;
}
