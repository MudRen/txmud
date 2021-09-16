// damo-sword.c 达摩剑

inherit SKILL;

mapping *action = ({
([      "action":"$N手中$w嗡嗡微振，一招「万事随缘」，刺向$n的$l",
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "刺伤"
]),
([      "action":"$N错步上前，使出「来去如梦」，剑意若有若无，$w罩向$n的$l",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "割伤"
]),
([      "action":"$N一式「佛法无边」，身形忽左忽右，手中$w向$n罩去",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "割伤"
]),
([      "action":"$N纵身轻轻跃起，一式「轮回法舟轻」，剑光如轮疾转，霍霍斩向$n的$l",
        "dodge" : 10,
        "damage": 55,
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w中宫直进，一式「水月禅寂」，无声无息地对准$n的$l刺出一剑",
        "dodge" : 35,
        "damage": 160,
        "damage_type":  "刺伤"
]),
([      "action":"$N气运全身，内力灌注于$w逼出丈许剑芒，一式「斩妖降魔」刺向$n的$l",
        "dodge" : 60,
        "damage": 155,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
	object ob;

	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力不够，无法修习达摩剑法。\n");
	if( (me->query_skill("dacheng-fofa",1) <= 50)
	|| (me->query_skill("damo-sword",1) >= me->query_skill("dacheng-fofa",1)) )
		return notify_fail("你的大成佛法修为不够，无法修习达摩剑法。\n");

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
	if( (int)me->query("kee") < 30 || (int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习达摩剑法。\n");
	me->receive_damage("kee", 30, "tire");
	me->add("force", -3);
	write("你按著所学练了一遍达摩剑法。\n");
	return 1;
}

int effective_level() { return 12;}

int learn_bonus()
{
	return -20;
}

int practice_bonus()
{
	return -40;
}

int black_white_ness()
{
	return -10;
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
	return CLASS_D("shaolin") + "/damo-sword/" + action;
}
