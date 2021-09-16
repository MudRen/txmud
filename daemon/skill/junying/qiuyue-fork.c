// qiuyue-fork.c
#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "name":                 "寒鸦望月",
                "action":               "$N使一招「寒鸦望月」，手中$w由下往上，疾刺向$n的$l",
                "dodge":                20,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "万鸟归林",
                "action":               "$N身形一转，一招「万鸟归林」$w化成一团光影，罩向$n的$l",
                "damage":               90,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "万籁俱寂",
                "action":               "$N身形侧闪，一招「万籁俱寂」手中$w无声无息的刺向$n的$l",
                "dodge":                -30,
                "damage_type":  "刺伤"
       ]),
        ([      "name":                 "落叶归根",
                "action":               "$N猛地向下一伏，手中$w一抖，使出「落叶归根」扫向$n的下盘",
                "dodge":                -10,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "秋风扫落叶",
                "action":               "$N使出一招「秋风扫落叶」手中$w如狂风暴雨般，往$n的$l刺去",
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "凉秋未寒",
                "action":               "$N手中$w轻轻点出，中途一变，一招「凉秋未寒」往$n的$l撩去",
                "damage":               150,
                "damage_type":  "刺伤"
        ]),
});
int valid_learn(object me)
{
 object ob;
        if( (int)me->query("max_force") < 30 )
                return notify_fail("你的内力不够，没有办法练秋月枪法。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "fork" )
                return notify_fail("你必须先找一把枪才能练枪法。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="fork" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 10 )
                return notify_fail("你的内力或气不够，没有办法练习秋月枪法。\n
");
        me->receive_damage("kee", 50);
        me->add("force", -10);
        write("你按著所学练了一遍秋月枪法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{

}

int effective_level() { return 15;}

string *parry_msg = ({
        "$n使出一招「"+HIB"付与高阳俦侣"NOR+"」，手中$v分两处，封住了$N的攻势。\n",
        "$n一抖手中的$v，使出一招「正店舍无烟"NOR+"」，手中的$v护住了全身。\n",
        "$n将$v往地上一点，$v反弹起来，刚好直刺$N的双臂。\n",
});
string *unarmed_parry_msg = ({
        "$n使出一招「"+HIB"付与高阳俦侣"NOR+"」，手中$v分两处，封住了$N的攻势。\n",
        "$n一抖手中的$v，使出一招「"+HIB"正店舍无烟"NOR+"」，手中的$v护住了全身。\n",
        "$n将$v往地上一点，$v反弹起来，刚好直刺$N的双臂。\n",
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
        return 5;
}
int practice_bonus()
{
        return 5;
}
int black_white_ness()
{
        return  15;
}
string perform_action_file(string action)
{
        return CLASS_D("junying") + "/qiuyue-fork/" + action;
}
