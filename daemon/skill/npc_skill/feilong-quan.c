// feilong-quan.c
// 飞龙服虎拳。(巡捕专用)

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":
"$N一式「黑龙探珠」，双拳从一个怪异的角度伸出，挥向$n的$l",
                "dodge":                -30,
                "parry":                50,
                "force":                90,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N身形一转，一招「冲天炮」右拳自下而上撩向$n的$l",
                "dodge":                -40,
                "parry":                100,
                "force":                110,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N双足一顿，一招「饿虎扑食」连人带拳扑至$n身前，如秋风之势击向$n的$l",
                "dodge":                -30,
                "parry":                120,
                "force":                160,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N猛一转身，背对$n，使出「弯弓射月」，右肘向$n的$l猛击",
                "dodge":                -50,
                "parry":                200,
                "force":                190,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
       return 0;
}

int valid_enable(string usage) { return usage=="unarmed"; }

int effective_level() {return 15;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	return 0;
}

string *parry_msg = ({
	"$n深吸一口气，就象粘在$N的$w上一样。\n",
	"$n身子微微一侧，已躲开$N的攻势。\n",
	"$n一招「浅海蛟龙」，不退反进，击向$N，逼得$N回招自保。\n",
});

string *unarmed_parry_msg = ({
        "$n一招「浅海蛟龙」，不退反进，击向$N，逼得$N回招自保。\n",
        "$n双拳错落，护住全身要害。\n",
});

string query_parry_msg(object weapon)
{
	return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
	return CLASS_D("npc_skill") + "/feilong-quan/" + action;
}

