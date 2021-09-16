// jiaohua-stick �л�����

inherit SKILL;
mapping *action = ({
([  "action": "$N�����һ�Σ���Ҫ���ɨ����$wȴֱֱ����$n��$l��ȥ",
        "dodge": 0,
        "force": 40,
        "damage_type": "����"
]),
([  "action": "$N���һ��������$w��ͷ�����ؾ���$n��ȥ",
        "dodge": 0,
        "force": 50,
        "damage_type": "����"
]),

([  "action": "$N�ֱ���������$w����������$n��$lɨȥ",
        "dodge": 0,
        "force": 50,
        "damage_type": "����"
]),

});


int valid_enable(string usage) { return (usage == "stick") || (usage == "parry"); }

int effective_level() { return 10;}

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("������������ۺ��޷�ѧϰ�л�������\n");
        if ((int)me->query_skill("stick", 1) < 50)
                return notify_fail("��Ļ������������������޷�ѧϰ�л�������\n");
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
        || (string)weapon->query("skill_type") != "stick")
                return notify_fail("��Ӧ������װ��������Ϊ������\n");
        if( (int)me->query("kee") < 30 || (int)me->query("force") < 30 )
                return notify_fail("��Ŀǰ����״��̫��޷���ϰ�л�������\n");
        me->receive_damage("kee", 10, "tire");
        me->add("force", -10);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("gaibang") + "/jiaohua-stick/" + action;
}

string *parry_msg = ({
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

