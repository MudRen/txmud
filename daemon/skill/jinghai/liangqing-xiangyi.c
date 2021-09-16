// liangqing-xiangyi.c from mool

inherit SKILL;

mapping *action = ({
([  "action" : "$N��ǰ����һ����һ�С���𡹣�����$w����������$n��$l������ȥ",
        "damage":60,
    "damage_type" : "����"
]),
([  "action" : "$N����Ծ�����ֽ���������һ����$w�����������٣�һʽ��������ӳ��ֱ��$n��$l",
        "damage":80,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�ѩӿ���ء���$w�����������⣬���¶��Ϸ���$n��$l",
        "damage":100,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С���С�������$w���ƺ�ɨʵ��б��������$n��$l",
        "damage":120,
    "damage_type" : "����"
]),
([  "action" : "$Nʹ����˼���$w����������������಻�ϻ���$n��$l",
        "damage":140,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С��ƺ����项������һ�󽣾�������$w���϶������������ֱ��$n��$l������ȥ",
        "damage":160,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С��������ࡹ�����ڰ�գ�$w�س飬���ֹ���$n��$l",
        "damage":180,
    "damage_type" : "����"
]),
([  "action" : "$N��Ӱһ��, �Ƶ�$n����һ�С��������ޡ���������$n��$l����",
        "damage":200,
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword")||(usage=="parry"); }
int practice_skill(object me)
{
        if(me->query_skill("jinghai-force",1) > 100)
                return 1;
        else
                return notify_fail("������ֻ����ѧ�ġ�\n");
}


int valid_learn(object me)
{
        if((int)me->query_skill("bibo-sword", 1)<100)
       return notify_fail("��ı̲�������򲻹���\n");
    if ((int)me->query_skill("moonlight-sword", 1) < 100)
       return notify_fail("����¹⽣�����̫ǳ��\n");
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
        "$n����$v����$N��$w��������$N��$w��\n",
       "$n�����е�$v����Ƿ��겻͸����ס��$N�Ĺ��ơ�\n",
});
string *unarmed_parry_msg = ({
	"$n�����е�$v����Ƿ��겻͸����ס��$N�Ĺ��ơ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
