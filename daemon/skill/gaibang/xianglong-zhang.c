// xianglong-zhang.c 降龙十八掌
// by dicky

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N双腿微曲，双掌平平提到胸前，右臂划个圆圈，呼的一声，一招「"HIY"亢龙有悔"NOR"」拍向$n",
        "dodge": 10,
        "damage": 40,
        "lvl" : 30,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然飞起半空，身形旋转，双掌居高临下一招「"HIY"飞龙在天"NOR"」直向身下的$n压去",
        "dodge": -5,
        "damage": 45,
        "lvl" : 40,
        "damage_type": "瘀伤"
]),
([      "action": "$N一招未完，一招又起，左掌回收，右掌向右一招「"HIY"见龙在田"NOR"」，迅捷无比地劈向$n的$l",
        "dodge": -10,
        "damage": 50,
        "lvl" : 50,
        "damage_type": "瘀伤"
]),
([      "action": "$N凝神闭气，双掌齐胸平推，施出这招「"HIY"鸿渐于陆"NOR"」，掌力夹带着隐隐风声推向$n",
        "dodge": -5,
        "damage": 55,
        "lvl" : 60,
        "damage_type": "瘀伤"
]),
([      "action": "$N右掌聚成拳状，格开$n手臂，接着左掌向前推一招「"HIY"潜龙勿用"NOR"」，掌力缓缓压向$n",
        "dodge": -10,
        "damage": 60,
        "lvl" : 70,
        "damage_type": "内伤"
]),
([      "action": "爆喝声中$N飞身上前，单掌劈出一招「"HIY"利涉大川"NOR"」，降龙掌掌风如刀，划向$n的$l",
        "dodge": 5,
        "damage": 65,
        "weapon" : "降龙掌掌风",
        "lvl" : 80,
        "damage_type": "割伤"
]),
([      "action": "$N双掌相并，身体突然前跃，使出「"HIY"突如其来"NOR"」这招，掌力排山倒海般向$n正面推出",
        "dodge": 10,
        "damage": 70,
        "lvl" : 90,
        "damage_type": "瘀伤"
]),
([      "action": "$N大吼一声，空门大开，双掌一上一下使出「"HIY"震惊百里"NOR"」，不顾一切地斩击$n",
        "dodge": -25,
        "damage": 75,
        "lvl" : 100,
        "damage_type": "瘀伤"
]),
([      "action": "$N跨前一步，一招「"HIY"或跃在渊"NOR"」，左右双掌向$n连连拍出，掌风更带起地上无数沙石",
        "dodge": -10,
        "damage": 80,
        "lvl" : 120,
        "damage_type": "瘀伤"
]),
([      "action": "$N身形向前移动，双掌分使两式「"HIY"双龙取水"NOR"」，凌厉的掌风一左一右同时压向$n$l",
        "dodge": -10,
        "damage": 85,
        "lvl" : 140,
        "damage_type": "瘀伤"
]),
([      "action": "$N左脚微曲，身形飞起，于半空中拍出「"HIY"鱼跃于渊"NOR"」，双掌立砍，齐向$n的$l劈下",
        "dodge": -5,
        "damage": 90,
        "weapon" : "手掌",
        "lvl" : 160,
        "damage_type": "割伤"
]),
([      "action": "$N扎个马部，使出招「"HIY"时乘六龙"NOR"」，双掌一正一反向$n周身连连续续猛烈砍了十数下",
        "dodge": -10,
        "damage": 95,
        "lvl" : 180,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出一招「"HIY"密云不雨"NOR"」，左掌掌力拍出，封住$n的退路，右掌斜斜地劈向他的$l",
        "dodge": -10,
        "damage": 100,
        "weapon" : "降龙掌掌力",
        "lvl" : 200,
        "damage_type": "割伤"
]),
([      "action": "$N弓步向前，一招「"HIY"损则有孚"NOR"」，双掌看似软绵绵地拍向$n，但地上的沙石却连连飞起",
        "dodge": -15,
        "damage": 105,
        "lvl" : 220,
        "damage_type": "内伤"
]),
([      "action": "$N脚下一转，突然欺身到$n身前，右掌护身，左掌一招「"HIY"龙战于野"NOR"」，猛然砍向$n的$l",
        "dodge": -5,
        "damage" : 20,
        "damage": 110,
        "weapon" : "掌缘",
        "lvl" : 240,
        "damage_type": "割伤"
]),
([      "action": "$N一声爆喝，胸前门户大开，双掌相并，齐向$n猛地推去，正是一招「"HIY"履霜冰至"NOR"」",
        "dodge": -25,
        "damage": 115,
        "lvl" : 260,
        "damage_type": "瘀伤"
]),
([      "action": "$N左掌低垂，右掌抬高，使出一招「"HIY"羝羊触蕃"NOR"」，两股雄浑的掌力同时向中间的$n挤压下去",
        "dodge": 5,
        "damage": 120,
        "lvl" : 280,
        "damage_type": "瘀伤"
]),
([      "action": "但见$N左掌护胸，身体后转，右掌紧跟着一摆，一招「"HIY"神龙摆尾"NOR"」拍向身后的$n",
        "dodge": 15,
        "damage": 125,
        "lvl" : 300,
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) 
{ return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练降龙十八掌必须空手。\n");

        if ((int)me->query_skill("gaibang-force", 1) < 100)
                return notify_fail("你的丐帮心法火候不够，无法练降龙十八掌。\n");

        if( me->query("gender") == "中性神")
                return notify_fail("你一个不男不女之人怎能学习降龙掌？\n");

        if ((int)me->query("max_force") < 2000)
                return notify_fail("你的内力太弱，无法学降龙十八掌。\n");

        if ((int)me->query_str() < 100 )
                return notify_fail("你没有雄壮的臂力无法学降龙十八掌。\n");

        if ((int)me->query_con() < 60)
                return notify_fail("你没有雄厚的体质无法学降龙十八掌。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{

        return action[random(sizeof(action))];
/*
        int i,level,n;

        level = (int) me->query_skill("xianglong-zhang",1);

        n = sizeof(action);
        for(i=0;i<n;i++)
                if(level >= action[i]["lvl"])
                        return action[random(i)];
*/
} 

int practice_skill(object me)
{
        int lvl = (int)me->query_skill("xianglong-zhang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("gin") < 20)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 30)
                return notify_fail("你的内力不够练降龙十八掌。\n");

        me->receive_damage("jingli", 20);
        me->add("force", -30);
        return 1;
}

int effective_level() { return 12;}

string perform_action_file(string action)
{
	return CLASS_D("gaibang") +"/xianglong-zhang/" + action;
}

string *parry_msg = ({
"$p不待回身，半招「"HIY"神龙摆尾"NOR"」，做势反劈。$P见这招势凶狠，不敢硬接，纵身避开。\n",
"只见$p左掌圆劲，右掌直推，挡在身前。一招纯是防御，却是在双方之间布了一道坚壁。\n",
"$p当下不敢怠慢，双掌当胸平推，将自己全身笼罩在掌力之下。守得稳若渊停岳峙，直无半点破绽。\n",
});

string *unarmed_parry_msg = ({
        "$n扎个马部，使出招「随风落叶」，化解了$N的攻势。\n",
});


string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
