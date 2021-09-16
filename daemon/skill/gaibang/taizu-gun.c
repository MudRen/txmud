// taizu-gun.c 太祖棍法
// by pian

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": HIG"$N一式"+WHT"「细草微风岸」"+HIG"，手中$w"+HIG"幻出一片棍影洒向$n的$l"NOR,
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "淤伤"
]),
([      "action": HIG"$N错步上前，力透$w"+HIG"，正是一式"+WHT"「危墙独夜舟」"+HIG"，棍影点点向$n的$l挥去"NOR,
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "刺伤"
]),
([      "action": HIG"$N一式"+WHT"「星垂平野阔」"+HIG"，纵身飘开数尺，手中$w"+HIG"却挥向$n的$l"NOR,
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "淤伤"
]),
([      "action": HIG"$N纵身轻轻跃起，一式"+WHT"「月涌大江流」"+HIG"，棍影飘飘疾转，霍霍斩向$n的$l"NOR,
        "dodge" : 10,
        "damage": 55,
        "damage_type":  "割伤"
]),
([      "action": HIG"$N手中$w"+HIG"中宫直进，一式"+WHT"「晓风残月」"+HIG"，无声无息地对准$n的$l刺出一剑"NOR,
        "dodge" : 35,
        "damage": 160,
        "damage_type":  "刺伤"
]),
([      "action": HIG"$N手中$w"+HIG"斜指，一式"+WHT"「飘飘何所以」"+HIG"，对准$n的$l斜斜击出"NOR,
        "dodge" : 5,
        "damage": 45,
        "damage_type":  "刺伤"
]),
([      "action": HIG"$N左指凌空虚点，右手$w"+HIG"一式"+WHT"「天地一沙鸥」"+HIG"刺向$n的$l"NOR,
        "dodge" : 60,
        "damage": 155,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_force") < 20 )
		return notify_fail("你的内力不够，没有办法练『太祖棍法』。\n");

	if( (string)me->query_skill_mapped("force")!= "taizu-force")
		return notify_fail("修习『太祖棍法』必须要『太棍心法』配合。\n");

	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "stick" )
		return notify_fail("你必须先找一根棍子才能练『太祖棍法』。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	|| (int)me->query("force") < 30 )
		return notify_fail("你的内力或气不够，没有办法练习『太祖棍法』。\n");

	me->receive_damage("kee", 20);
        me->add("force", -3);

	write("你按著所学练了一遍太祖棍法。\n");
	return 1;
}

int effective_level() { return 10;}

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
        return CLASS_D("gaibang") + "/taizu-gun/" + action;
}
