// chuanyun-zhang.c ���ƴ߻���
// by dicky

/*
     ����̽�� ���˾�� �׺����� ���˶���
���� �봰���� �������� ����׷�� ��������
���� �������� ŭ����ɽ �ṭ׽�� ��Գ����
*/

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһʽ������̽�ס���������Σ���������ͻȻ����$n����ǰ��Ѩ",

        "damage":50,
        "damage_type" : "����"
]),
([      "action" : "$N����һ�Σ�һʽ�����˾�ۡ�����������$n�ļ�ͷ����ȭ����$n���ؿ�",
        "damage":60,
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ���������С������ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
        "damage":70,
        "damage_type" : "����"
]),
([      "action" : "$N�������У�����ֱ����һʽ�����˶��ס�����Ʈ��������$n������",
        "damage":80,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ������׷�󡹣���ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
        "damage":90,
        "skill_name" : "����׷��",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ���������硹��ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
        "damage":100,
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֱ�ȭ��һʽ��ŭ����ɽ������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
        "damage":105,
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ����Գ���ס���ȭ���������֣��������ޣ�����������$n�ĵ���",
        "damage":110,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) 
{ return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����ƴ߻��Ʊ�����֡�\n");
        if ((int)me->query_skill("taxue-force", 1) < 30)
                return notify_fail("���̤ѩ�񹦻�򲻹����޷�ѧ���ƴ߻��ơ�\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������̫�����޷������ƴ߻��ơ�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 15)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 15)
                return notify_fail("��������������ƴ߻��ơ�\n");
        me->receive_damage("kee", 20);
        me->add("force", -10);
        return 1;
}

int effective_level() { return 12;}

string perform_action_file(string action)
{
	return CLASS_D("taxue") +"/chuanyun-zhang/" + action;
}

string *parry_msg = ({
        "$nһ�С��ṭ׽������˫������$N��$w������\n",
});

string *unarmed_parry_msg = ({
        "$n˫��һ�죬һ�С��������䡹��������$N�Ĺ��ơ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
