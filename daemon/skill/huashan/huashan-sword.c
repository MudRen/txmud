// huashan huashan-sword.c 华山剑法

inherit SKILL;

mapping *action = ({
([      "action":"$N使一式「苍松迎客」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "刺伤"
]),
([      "action":"$N错步上前，使出「古柏参天」，剑意若有若无，$w淡淡地向$n的$l挥去",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "割伤"
]),
([      "action":"$N一式「举火燎日」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "割伤"
]),
([      "action":"$N纵身轻轻跃起，一式「浮云过山」，剑光如轮疾转，霍霍斩向$n的$l",
        "dodge" : 10,
        "damage": 55,
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w中宫直进，一式「晓风残月」，无声无息地对准$n的$l刺出一剑",
        "dodge" : 35,
        "damage": 160,
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w斜指苍天，剑芒吞吐，一式「山山枫火」，对准$n的$l斜斜击出",
        "dodge" : 5,
        "damage": 45,
        "damage_type":  "刺伤"
]),
([      "action":"$N左指凌空虚点，右手$w逼出尽许雪亮剑芒，一式「水寂天赖」刺向$n的$l",
        "dodge" : 60,
        "damage": 155,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_force") < 20 )
		return notify_fail("你的内力不够，没有办法练『华山剑法』。\n");

	if( (string)me->query_skill_mapped("force")!= "zixia-force")
		return notify_fail("修习『华山剑法』必须要『紫霞神功』配合。\n");

	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练『华山剑法』。\n");
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
	|| (int)me->query("force") < 30 )
		return notify_fail("你的内力或气不够，没有办法练习『华山剑法』。\n");

	me->receive_damage("kee", 20);
        me->add("force", -3);

	write("你按著所学练了一遍华山剑法。\n");
	return 1;
}

int effective_level() { return 12;}

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
string *parry_msg = ({
        "结果$n用手中的$v格开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
	"$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/huashan-sword/" + action;
}
