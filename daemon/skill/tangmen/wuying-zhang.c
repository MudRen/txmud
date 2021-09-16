// wuying-zhang.c
// ���� ��Ӱ������

inherit SKILL;

mapping *action = ({
([      "action" : "$N�����ϲ���һʽ���嶾���ġ�������ץ��$n��$l",
        "force" : 10,
        "dodge" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N����һԾ��һ�С���Ӱ��꡹��˫������$n��$l",
        "force" : 20,
        "dodge" : 30,
        "damage_type" : "����"
]),
([      "action" : "$N����Ų����һʽ��Ҵ��͵�ҡ�����ȭ��$n��$l��ȥ",
        "force" : 30,
        "dodge" : 30,
        "damage_type" : "����"
]),
([      "action" : "$N��ȫ��������������֮�ϣ�˫������Ʈ��$n��$l",
        "force" : 40,
        "dodge" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N����ƽƽ��ǰ�����ַ���$n��$l",
        "force" : 50,
        "dodge" : 50,
        "damage_type" : "����"
]),

});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
	return (usage=="unarmed") || (usage=="throwing");
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

int effective_level() { return 11;}

string *parry_msg = ({
	"$n˫��һ����$N���е�$w��ƫ��һ�֣���$n�����Է��˹�ȥ��\n",
});
string *unarmed_parry_msg = ({
	"$nһ�С����߳����������ɵĵ�����$N����ʽ��\n",
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
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
	return CLASS_D("tangmen") + "/wuying-zhang/" + action;
}
