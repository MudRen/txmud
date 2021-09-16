// lianhuan-blade.c
// ��������(Ѳ��ר��)

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$wбָ��һ�С�ͣ����·��������һ�٣�һ����$n��$l��ȥ",
        "force" : 120,
        "dodge" : -10,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ͯ�Ӱݷ𡹣���������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
        "dodge" : -10,
        "damage" : 45,
        "damage_type" : "����"
]),
([      "action" : "$Nչ���鲽������Ծ�䣬һ�С��ƴ����¡�������һ������ն��$n",
        "damage" : 45,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ż�ɽ����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
        "damage" : 25,
        "damage_type" : "����"
]),

});

int valid_learn(object me)
{
	return 0;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	return 0;
}

int effective_level() { return 15;}

string *parry_msg = ({
        "$n����һ�Σ������е�$v����$N����ָ��\n",
        "$n���˷��������е�$vֱ��$N��$w��˫�֡�\n",
});

string *unarmed_parry_msg = ({
        "$n����һ�Σ������е�$v����$N����ָ��\n",
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
	return CLASS_D("npc_skill") + "/lianhuan-blade/" + action;
}
