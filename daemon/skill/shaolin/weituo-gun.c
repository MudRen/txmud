// weituo-gun.c 韦陀棍
// 特攻：韦陀降魔 xiangmo

inherit SKILL;

mapping *action = ({
([      "action":"$N手中一招「叱咤风云」，$w舞起一朵棍花，向$n的砸去。",
        "damage": 40,
        "damage_type":"挫伤"
]),
([      "action":"$N飞身跃起，手中$w化成一线，一招「撑天拄地」，猛地向$n的$l点去",
        "damage": 65,
        "damage_type":"挫伤"
]),
([      "action":"$N一招「冠盖如云」，手中$w带着风声向$n的劈头盖脸的砸去。",
        "damage": 80,
        "damage_type":"挫伤"
]),
([      "action":"$N伏地一个滚翻，一招「烘云托月」，手中$w挟呼呼风声迅猛扫向$n的$l",
        "force" : 250,
        "dodge" : 15,
        "parry" : 5,
        "damage": 25,
        "damage_type":"挫伤"
]),
([      "action":"$N双手持棍划了个天地大圈，一招「红霞贯日」，一棍从圆心正中击出，撞向$n的胸口",
        "damage": 95,
        "damage_type":"挫伤"
]),
([      "action":"$N力透$w，一招「金针度人」，矫龙般直射$n的$l",
        "damage": 50,
        "damage_type":"挫伤"
]),
});

int valid_learn(object me)
{
	object weapon;
	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "stick")
		return notify_fail("你必须先找一根棍子，才能学习韦陀棍。\n");
	if((int)me->query("max_force") < 100)
		return notify_fail("你的内力太低，无法学习韦陀棍。\n");
	if(me->query_skill("weituo-gun",1) >= me->query_skill("yiqi-force",1))
		return notify_fail("你的混元一气功功力不够，无法学习韦陀棍。\n");

        return 1;
}

int valid_enable(string usage)
{
	return (usage=="stick") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	me->receive_damage("kee", 25,"tire");
	return 1;
}

int effective_level() { return 10;}

string *parry_msg = ({
        "$n手中$v急点$N的$w，荡开了$N的$w。\n",
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
        return -10;
}

string perform_action_file(string action)
{
	return CLASS_D("shaolin") + "/weituo-gun/" + action;
}
