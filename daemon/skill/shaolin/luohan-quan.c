// luohan-quan.c 罗汉拳

inherit SKILL;

mapping *action = ({
([      "action" : "$N连续上步，一式「黄莺落架」，左右手分靠，变拳为掌，击向$n的$l",
        "force" : 10,
        "dodge" : 20,
        "skill_name" : "黄莺落架",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左脚虚踏，全身右转，一招「丹凤朝阳」，右掌猛地插向$n的$l",
        "force" : 20,
        "dodge" : 30,
        "skill_name" : "丹凤朝阳",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手大开大阖，宽打高举，使一招「洛钟东应」，双拳向$n的$l打去",
        "force" : 30,
        "dodge" : 30,
        "skill_name" : "洛钟东应",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左掌圈花扬起，屈肘当胸，虎口朝上，一招「偏花七星」打向$n的$l",
        "force" : 40,
        "dodge" : 10,
        "skill_name" : "偏花七星",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一招「苦海回头」，上身前探，双手划了个半圈，击向$n的$l",
        "force" : 50,
        "dodge" : 5,
        "skill_name" : "苦海回头",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双掌划弧，一记「挟山超海」，掌出如电，一下子切到$n的手上",
        "force" : 70,
        "dodge" : 30,
        "skill_name" : "挟山超海",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N施出「慑服外道」，双拳拳出如风，同时打向$n头，胸，腹三处要害",
        "force" : 80,
        "dodge" : -10,
        "skill_name" : "慑服外道",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左脚内扣，右腿曲坐，一式「三入地狱」，双手齐齐按向$n的胸口",
        "force" : 100,
        "dodge" : -20,
        "skill_name" : "三入地狱",
        "damage_type" : "瘀伤"
]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练罗汉拳法必须空手。\n");
	if(me->query_skill("changquan",1) <= 100)
		return notify_fail("你的少林长拳基础不够，无法学习罗汉拳。\n");
	if(me->query_skill("yiqi-force",1) <= 100)
		return notify_fail("你的混元一气功功力不够，无法学习罗汉拳。\n");
        return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	me->receive_damage("kee", 30, "tire");
	return 1;
}

int effective_level() { return 12;}

string *parry_msg = ({
	"$n一招「普渡众生」，猛击$N的面门，逼得$N中途撤回手中的$w。\n",
	"$n右拳虚幌，左拳一招「菩提本无树」，逼得$N后退三步。\n",
	"$n以守为攻，一招「明镜亦非台」，猛击$N握$w的手腕。\n",
});
string *unarmed_parry_msg = ({
	"$n一招「普渡众生」，逼得$N中途撤招。\n",
	"$n脚走阴阳，一招「菩提本无树」，攻$N之必救。\n",
	"$n左拳击下，右拳自保，一招「明镜亦非台」，将$N封于尺外。\n",
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
	return -30;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return -40;
}

string perform_action_file(string action)
{
	return CLASS_D("shaolin") + "/luohan-quan/" + action;
}
