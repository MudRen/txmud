// fenghui-sword.c 风回雪舞剑
// by dicky

#include <ansi.h>
inherit SKILL;

string  *msg = ({
"$N右手$w斜指而下，左手五指正在屈指而数，从一数到五，握而成拳，又将拇指伸出，次
而食指，终至五指全展，跟着又屈拇指而屈食指，再屈中指，然后手中$w剑光暴长，向
$n的$l刺去",
"$N展开剑势，身随剑走，左边一拐，右边一弯，越转越急。猛地$w剑光暴长，一招「秋风
扫落叶」往$n$l刺去",
"$N手中$w倏地刺出，一连五剑，每一剑的剑招皆苍然有古意。招数古朴，内藏奇变，正是
「大智若愚」",
"$N回身拧腰，右手双指捏了个指诀，左手挥$w向后反撩而上，一式「峰回路转」，剑势
如匹练般撩向$n的$l",
"$N提剑顺刺，逆击，横削，倒劈，无不是剑法的入门，当真返朴归真，已不存任何破绽",
"$N左足一点，身形后撤，忽然又纵身向前，剑意如音缈九天，一招「清风万里」，$w轻飘
飘地直逼$n", 
"$N祭起手中之剑，左手捏成剑诀，咄喝一声，空中满是剑影，宛若千道银链，在$n身边游
动",
"$N使出「响隔楼台」，$w斜指向上，剑锋直出却又抑扬，忽缓忽急地刺向$n的$l", 
"$N剑势如虹，无可当锋，$n惊怖中更觉剑力有如海潮一般，一波一浪阵阵涌来，绵延不绝",
});

int valid_enable(string usage)
{ return usage=="sword" || usage=="parry"; }

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，无法修炼风回雪舞剑。\n");

	if(me->query_skill("taxue-force", 1) < 30)
		return notify_fail("你的踏雪神功修为不够，无法修炼风回雪舞剑。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i;
        i = random(me->query_skill("fenghui-sword"))/5;

        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(50)+i),
                "dodge": random(10)+5,
                "damage_type":random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够，练不了风回雪舞剑。\n");
	me->receive_damage("kee", 35,"tire");
	return 1;
}

int effective_level() { return 12;}
//int effective_parry_level() { return 12; }

string perform_action_file(string action)
{
        return CLASS_D("taxue") + "/fenghui-sword/" + action;
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