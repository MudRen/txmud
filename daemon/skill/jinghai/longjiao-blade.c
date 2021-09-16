// longjiao-blade.c from mool

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$wбָ��һ�С�����һ�ơ�������һ�٣�һ����$n��$l��ȥ",
        "damage":50,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ն������������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
        "damage":60,
        "damage_type" : "����"
]),
([      "action" : "$Nչ���鲽������Ծ�䣬һ�С��������ˡ������滯������ն��$n",
        "damage":70,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����»�������$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
        "damage":80,
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ����һ�С���ˮ��ħ����˫�ֳ����������У�����$n���ؿ�",
        "damage":90,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��һ�С���ٲ��������������ã����ҿ�����������$n",
        "damage":100,
        "damage_type" : "����"
])
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("jinghai-force", 1) < 10)
                return notify_fail("��ľ����񹦻��̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("������������޷���ϰ����ն�޵�����\n");
        me->receive_damage("kee", 25);
        return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("jinghai") +"/longjiao-blade/" + action;
}

int effective_level() { return 11;}

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
