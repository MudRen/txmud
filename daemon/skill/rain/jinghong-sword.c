// jinghong-sword.c
// 绯雨惊鸿剑法

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N一招「红日初升」，手中$w冲天而刺，瞬间又斜斜的刺向n的$l",
                "dodge":                -10,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出的「烈日炎炎」，手中的$w舞成了一片剑网罩向$n的$l",
                "dodge":                10,
                "damage":               60,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出「心如天鸿」，手中$w微微轻颤，有如毒蛇般刺向$n的$l",
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w以一式「死心复燃」，身形暴起，手中$w自空中劈向$n的$l。",
                "dodge":                40,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中的$w忽然不可思议的刺出，一招「逆天而行」，从一个怪异的角度连刺$n数剑",
                "dodge":                30,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一式「银河倒泻」，手中的$w一连六剑刺向$n的$l",
                "dodge":                60,
                "damage":               130,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一式「噩梦惊魂」，手中的$w化为一道诡异的剑光，刺向$n的$l",
                "dodge":                30,
                "damage":               60,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一招「人醉心碎」，抛起手中的$w，双掌连缠$n，而$w却从天而降，刺向$n的$l",
                "dodge":                -30,
                "damage":               140,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 30 )
                return notify_fail("你的内力不够，没有办法练『绯雨惊鸿剑法』。\n");

        if( (string)me->query_skill_mapped("force") != "suiyu-force")
                return notify_fail("『绯雨惊鸿剑法』必须配合『随雨无风心法』才能练。\n");

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
	if( (me->query("kee") < 40)
	|| (me->query("force") < 10) )
		return notify_fail("你的内力或气不够，没有办法练习『绯雨惊鸿剑法』。\n");
	me->receive_damage("kee", 30,"tire");
	me->add("force", -5);
	write("你按著所学练了一遍『绯雨惊鸿剑法』。\n");
	return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("rain") + "/jinghong-sword/" + action;
}
 
int effective_level() { return 12;}

string *parry_msg = ({
        "$n使出一招「幻风幻雨」，手中的$v虚晃几招，身形已闪开数丈。\n",
        "$n使出「飘风落雨」，手中的$v将$N的$w一一化解。\n",
        "$n使出一招「孤松斜立」，手中的$v歪走一招，缠住了$N的$w。\n",
        "$n手中的$v舞成一片剑幕，一招「古林遮日」守的密不透风。\n",
});

string *unarmed_parry_msg = ({
        "$n手中的$v花为一道虹光，反刺向$N。\n",
        "$n一式「萍水浮莲」，身形斜斜的飘开数丈。\n",
        "$n使出一招「阴气弥漫」，手中$v向$N连递数招后，身形斜飘而升。\n",
        "$n连换数种身形，鬼魅般的忽然消失了。\n",
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
