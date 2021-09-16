// zuiyue-strike.c
// 醉月明花掌

inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N一式「邀月飞花」，右掌一连三个虚招，袭向$n上三路，左掌紧跟其后，袭向$n下三路",
                "dodge":                -100,
                "parry":                100,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左掌画个半圆，护住中路，劲贯右掌，使出「圆月遮花」，攻向$n的$l",
                "dodge":                -100,
                "parry":                100,
                "force":                 70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「拈花赏月」，遥点一指，一屡锐风划空而出劈向$n手腕",
                "dodge":                -100,
                "parry":                100,
                "force":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形临空窜起，一式「花舞月随」，右掌掌心朝内，左掌掌心朝外，分攻$n上，中，下三路",
                "dodge":                -100,
                "parry":                100,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形退而复进，玉掌如飞，使出「纤月素翎」，向$n的$l拍出一缕缕劲风。",
                "dodge":                -100,
                "parry":                100,
                "force":                140,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N娇躯一跃而前，一招「残月斜升」，两只玉掌疾如风雷般向$n的$l练攻数招",
                "dodge":                -200,
                "parry":                200,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练『醉月明花掌』必须空手。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
	return CLASS_D("rain") + "/zuiyue-strike/" + action;
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if(me->query("force") < 10)
		return notify_fail("你的真气不够，休息一下再练吧。\n");
	me->add("force", -5);
	me->receive_damage("kee", 25,"tire");
	write("你按著所学练了一遍『醉月明花掌』。\n");
        return 1;
}

int effective_level() { return 12;}
 
string *parry_msg = ({
        "$n使出一招「芊芊素云」，纤掌练练拂扫，身形一动，又向后纵去。\n",
        "$n双掌舞的密不透风，一招「大雾弥漫」拍向$N的$w。\n",
        "$n使出「彩云追月」，双掌引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n一招「雨中霹雳」纤掌练练拂扫，身形一动，又向后纵去。\n",
        "$n施展出「随风随雨」，轻描淡写的化解了$N的攻势。\n",
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
        return 0;
}

int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 0;
}

