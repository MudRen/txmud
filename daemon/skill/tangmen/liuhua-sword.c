// liuhua-sword.c
// ������Ӱ��

inherit SKILL;

mapping *action = ({
([      "action":"$N��$wбб��������һ�С���������������$n��$l",
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "����"
]),
([      "action":"$N���е�$wһ����һʽ��������Ը������$n��$l",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "����"
]),
([      "action":"$N����һ������$n����������ʧ��$wȴ����$n��$l",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "����"
]),
([      "action":"$Nһ��ת��$w�����һ��һ����ɲ�Ǽ�ն��$n��$l",
        "dodge" : 10,
        "damage": 55,
        "damage_type":  "����"
]),
([      "action":"$N����$w�й�ֱ����������Ϣ�ض�׼$n��$l�̳�һ��",
        "dodge" : 35,
        "damage": 160,
        "damage_type":  "����"
]),
([      "action":"$N���е�$w��������â�������ӽ���������ֱ��$n��$l��ȥ",
        "dodge" : 60,
        "damage": 155,
        "damage_type":  "����"
]),
([      "action":"$N˫���ս�$w������͸�����������Ƽ�ƽ����һ����$n��$l��ȥ",
        "dodge" : 70,
        "damage": 180,
        "damage_type":  "����"
]),

});

int valid_learn(object me)
{
	object ob;

	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 || (int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ������Ӱ����\n");
	me->receive_damage("kee", 30, "tire");
	me->add("force", -3);
	write("�㰴����ѧ����һ��������Ӱ����\n");
	return 1;
}

int effective_level() { return 11;}

int learn_bonus()
{
	return -10;
}

int practice_bonus()
{
	return -10;
}

int black_white_ness()
{
	return -10;
}

string *parry_msg = ({
	"$v��$n������������$N��$w��\n",
});

string *unarmed_parry_msg = ({
	"$n���е�$v�γ���һ�����������ķ�ס��$N�Ĺ��ơ�\n",
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
	return CLASS_D("tangmen") + "/liuhua-sword/" + action;
}
