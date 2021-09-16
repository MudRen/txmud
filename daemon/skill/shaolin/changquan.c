// liuh-ken.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N一招「黑虎掏心」，对准$n的$l一拳打去",
		"force":		40,
		"parry":		20,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一招「举火烧天」双拳向$n的$l擂去",
		"force":		30,
		"parry":		10,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一招「疾风劲草」左手虚晃，右拳中宫直进便往$n的$l狠狠捶去",
		"force":		30,
		"parry":		10,
		"damage_type":	"瘀伤"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练少林长拳必须空手。\n");
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
	me->receive_damage("kee", 30);
	return 1;
}

int effective_level() { return 10;}

string *parry_msg = ({
	"$n一招「反客为主」，双掌拍向$N握$w的手腕。\n",
});

string *unarmed_parry_msg = ({
	"$n双拳环抱，一招「万象归空」，化解了$N的攻势。\n",
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
