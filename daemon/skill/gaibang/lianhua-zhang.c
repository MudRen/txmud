// lianhua-zhang.c 莲花掌
// by dicky

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N向后飘出尺许，转过身来，一招「咸言意气高」忽地左掌向后斜劈，飕的一声轻响切向$n的$l",
        "dodge" : -10,
        "force": 50,
        "damage_type": "瘀伤"
]),

([  "action": "$N起手一式「水寒风似刀」，右掌向后斜劈，荡起一股微风抚向$n的$l，不带丝毫霸气",
        "dodge" : -5,
        "force": 60,
        "damage_type": "瘀伤"
]),

([      "action": "$N微微一笑，出掌按向$n的$l，如行云、如流水，潇洒之极，正是那招「黯黯见临洮」",
        "dodge" : -10,
        "force": 70,
        "damage_type": "瘀伤"
]),

([  "action": "$N抬起头来，目不转瞬的向$n凝视，接着轻飘飘一转身「平沙日未没」左右两掌往后拍出",
        "dodge" : -10,
        "force": 80,
        "damage_type" : "内伤"
]),

([  "action": "$N身形随风飘动，一式「饮马渡秋水」左右轻拍连出五掌，五丝轻风绕过$N的身子悄然向$n的$l袭去",
        "dodge" : -15,
        "force": 80,
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) 
{ return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练莲花掌必须空手。\n");
        if ((int)me->query_skill("gaibang-force", 1) < 30)
                return notify_fail("你的丐帮心法火候不够，无法学莲花掌。\n");
        if ((int)me->query("max_force") < 400)
                return notify_fail("你的内力太弱，无法练莲花掌。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 35)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 15)
                return notify_fail("你的内力不够练莲花掌。\n");
        me->receive_damage("kee", 35);
        me->add("force", -15);
        return 1;
}

int effective_level() { return 11;}

string perform_action_file(string action)
{
	return CLASS_D("gaibang") +"/lianhua-zhang/" + action;
}

string *parry_msg = ({
        "$n一招「倒挂金钩」，双掌拍向$N握$w的手腕。\n",
        "$n双掌舞的密不透风，一招「直捣黄龙」拍向$N的$w。\n",

});

string *unarmed_parry_msg = ({
        "$n双臂一伸，一招「风起云涌」，化解了$N的攻势。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
