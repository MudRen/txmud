[0m
// chuanyun-zhang.c ���ƴ߻���
/*
     ����̽�� ���˾�� �׺����� ���˶���
���� �봰���� �������� ����׷�� ��������
���� �������� ŭ����ɽ �ṭ׽�� ��Գ����
*/
[0m
inherit SKILL;
[0m
mapping *action = ({
([      "action" : "$Nһʽ��[51m����̽��[0m����������Σ���������ͻȻ����$n����ǰ��Ѩ",
        "damage":50,
        "damage_type" : "����"
]),
([      "action" : "$N����һ�Σ�һʽ��[51m���˾��[0m������������$n�ļ�ͷ����ȭ����$n���ؿ�",
        "damage":60,
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��[51m��������[0m�������ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
        "damage":70,
        "damage_type" : "����"
]),
([      "action" : "$N�������У�����ֱ����һʽ��[51m���˶���[0m������Ʈ��������$n������",
        "damage":80,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ��[51m����׷��[0m������ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
        "damage":90,
        "skill_name" : "����׷��",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��[51m��������[0m����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
        "damage":100,
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֱ�ȭ��һʽ��[51mŭ����ɽ[0m������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
        "damage":105,
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��[51m��Գ����[0m����ȭ���������֣��������ޣ�����������$n�ĵ���",
        "damage":110,
        "damage_type" : "����"
]),
});
[0m
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
[0m
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����ƴ߻��Ʊ�����֡�\n");
        if ((int)me->query_skill("taxue-force", 1) < 1)
                return notify_fail("���̤ѩ�񹦻�򲻹����޷�ѧ���ƴ߻��ơ�\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������̫�����޷������ƴ߻��ơ�\n");
        return 1;
}
[0m
[0m
[0m
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
[0m
int practice_skill(object me)
{
        if ((int)me->query("kee") < 15)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 15)
                return notify_fail("��������������ƴ߻��ơ�\n");
        me->receive_damage("kee", 15);
        me->add("force", -15);
        return 1;
}
string perform_action_file(string action)
{
return CLASS_D("taxue") +"/chuanyun-zhang/" + action;
}
[0m
string *parry_msg = ({
        "$nһ�С�[51m�ṭ׽��[0m����˫������$N��$w������\n",
});
[0m
string *unarmed_parry_msg = ({
        "$n˫��һ�죬һ�С�[51m��������[0m����������$N�Ĺ��ơ�\n",
});
[0m
int effective_level() { return 12;}
[0m
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
