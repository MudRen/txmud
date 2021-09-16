// luohan-quan.c �޺�ȭ

inherit SKILL;

mapping *action = ({
([      "action" : "$N�����ϲ���һʽ����ݺ��ܡ��������ַֿ�����ȭΪ�ƣ�����$n��$l",
        "force" : 10,
        "dodge" : 20,
        "skill_name" : "��ݺ���",
        "damage_type" : "����"
]),
([      "action" : "$N�����̤��ȫ����ת��һ�С����ﳯ�����������͵ز���$n��$l",
        "force" : 20,
        "dodge" : 30,
        "skill_name" : "���ﳯ��",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ִ󿪴��أ����߾٣�ʹһ�С����Ӷ�Ӧ����˫ȭ��$n��$l��ȥ",
        "force" : 30,
        "dodge" : 30,
        "skill_name" : "���Ӷ�Ӧ",
        "damage_type" : "����"
]),
([      "action" : "$N����Ȧ���������⵱�أ����ڳ��ϣ�һ�С�ƫ�����ǡ�����$n��$l",
        "force" : 40,
        "dodge" : 10,
        "skill_name" : "ƫ������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ�С��ຣ��ͷ��������ǰ̽��˫�ֻ��˸���Ȧ������$n��$l",
        "force" : 50,
        "dodge" : 5,
        "skill_name" : "�ຣ��ͷ",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ƻ�����һ�ǡ�Юɽ���������Ƴ���磬һ�����е�$n������",
        "force" : 70,
        "dodge" : 30,
        "skill_name" : "Юɽ����",
        "damage_type" : "����"
]),
([      "action" : "$Nʩ��������������˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��",
        "force" : 80,
        "dodge" : -10,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$N����ڿۣ�����������һʽ�������������˫�����밴��$n���ؿ�",
        "force" : 100,
        "dodge" : -20,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("���޺�ȭ��������֡�\n");
	if(me->query_skill("changquan",1) <= 100)
		return notify_fail("������ֳ�ȭ�����������޷�ѧϰ�޺�ȭ��\n");
	if(me->query_skill("yiqi-force",1) <= 100)
		return notify_fail("��Ļ�Ԫһ���������������޷�ѧϰ�޺�ȭ��\n");
        return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 30, "tire");
	return 1;
}

int effective_level() { return 12;}

string *parry_msg = ({
	"$nһ�С��ն����������ͻ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
	"$n��ȭ��ϣ���ȭһ�С����᱾���������Ƶ�$N����������\n",
	"$n����Ϊ����һ�С��������̨�����ͻ�$N��$w������\n",
});
string *unarmed_parry_msg = ({
	"$nһ�С��ն����������Ƶ�$N��;���С�\n",
	"$n����������һ�С����᱾����������$N֮�ؾȡ�\n",
	"$n��ȭ���£���ȭ�Ա���һ�С��������̨������$N���ڳ��⡣\n",
});

string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int learn_bonus()
{
	return -30;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return -40;
}

string perform_action_file(string action)
{
	return CLASS_D("shaolin") + "/luohan-quan/" + action;
}
