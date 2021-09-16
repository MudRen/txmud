// feixue-liantian.c 飞雪连天/特攻 xue.c 漫天风雪

inherit SKILL;

mapping *action = ({
([      "action":"$N手一扬，使一式「飞雪满前村」，只听得嗖嗖数声，数枚$w前慢后快地向$n的$l射出",
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "刺伤",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action":"$N身形忽地高高跃起，使一式「飞雪似杨花」，手中数枚$w向$n急射而出",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "刺伤",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action":"$N一式「飞雪带春风」，手一掷，数枚$w急掠而出，到了$n身后忽然转头向$n后心飞去",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "刺伤",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action":"$N身形突地倒地向外滚出，一回身，使一招「飞雪迷胡天」，手中暗扣的数枚$w以迅雷不及掩耳之势射向$n下身",
        "dodge" : 10,
        "damage": 55, 
        "damage_type":  "刺伤",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action":"$N身形一闪，到了$n身后，反手一式「超腾若飞雪」，手中数枚$w向$n的后心要害击去",
        "dodge" : 35,
        "damage": 160,
        "damage_type":  "刺伤",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action":"$N一式「飞雪满乾坤」，突然双手连扬数下，十余枚$w，闪电般地飞向$n的前胸",
        "dodge" : 60,
        "damage": 155,
        "damage_type":  "刺伤",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
});

int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "throwing" )
                return notify_fail("没有暗器你怎么练飞雪连天。\n");

        if( (int)me->query("max_force") < 50 )
        if( (int)me->query("max_force") < 50 ) 
                return notify_fail("你的内力不够，无法学习飞雪连天。\n");
        if( (me->query_skill("tang-force",1) <= 15)
        || (me->query_skill("feixue-liantian",1) >= me->query_skill("tang-force",1)) )
                return notify_fail("你的唐门内功修为不够，无法学习飞雪连天。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" || usage=="parry" || usage=="unarmed";}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 || (int)me->query("force") < 3 )
                return notify_fail("你的内力或气不够，没有办法练习飞雪连天。\n");
        me->receive_damage("kee", 30, "tire");
        me->receive_damage("kee", 30, "tire"); 
        me->add("force", -3);
        write("你按著所学练了一遍飞雪连天。\n");
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
        "$n屈指一弹，一枚$v当的一声弹开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n扬手打出数枚$v，将面前封的密不透风，$N无奈撤去了攻势。\n",
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
        return CLASS_D("tangmen") + "/feixue-liantian/" + action;
}
