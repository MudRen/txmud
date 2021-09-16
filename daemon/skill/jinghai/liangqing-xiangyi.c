// liangqing-xiangyi.c from mool

inherit SKILL;

mapping *action = ({
([  "action" : "$N向前跨上一步，一招「离别」，手中$w自左向右向$n的$l缓缓划去",
        "damage":60,
    "damage_type" : "刺伤"
]),
([  "action" : "$N向上跃起，左手剑诀，右手一抖，$w剑光缦妙如瀑，一式「心心相映」直刺$n的$l",
        "damage":80,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「雪涌兰关」，$w闪起数道寒光，自下而上反挑$n的$l",
        "damage":100,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「情感」，手中$w看似横扫实则斜劈，刺向$n的$l",
        "damage":120,
    "damage_type" : "刺伤"
]),
([  "action" : "$N使出「思念」，$w挽出三个剑花，绵绵不断划向$n的$l",
        "damage":140,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「似海深情」，左手一捏剑诀，右手$w自上而下雷霆万钧般直向$n的$l劈乐下去",
        "damage":160,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「爱意绵绵」，身在半空，$w回抽，反手勾向$n的$l",
        "damage":180,
    "damage_type" : "刺伤"
]),
([  "action" : "$N身影一晃, 绕到$n背后，一招「情意无限」，剑尖向$n的$l疾挑",
        "damage":200,
    "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword")||(usage=="parry"); }
int practice_skill(object me)
{
        if(me->query_skill("jinghai-force",1) > 100)
                return 1;
        else
                return notify_fail("靖海神功只能用学的。\n");
}


int valid_learn(object me)
{
        if((int)me->query_skill("bibo-sword", 1)<100)
       return notify_fail("你的碧波剑法火候不够。\n");
    if ((int)me->query_skill("moonlight-sword", 1) < 100)
       return notify_fail("你的月光剑法火候太浅。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
return CLASS_D("jinghai") +"/liangqing-xiangyi/" + action;
}

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
