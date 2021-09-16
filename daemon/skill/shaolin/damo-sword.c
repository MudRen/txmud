// damo-sword.c ��Ħ��

inherit SKILL;

mapping *action = ({
([      "action":"$N����$w����΢��һ�С�������Ե��������$n��$l",
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "����"
]),
([      "action":"$N����ǰ��ʹ������ȥ���Ρ��������������ޣ�$w����$n��$l",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "����"
]),
([      "action":"$Nһʽ�����ޱߡ������κ�����ң�����$w��$n��ȥ",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "����"
]),
([      "action":"$N��������Ծ��һʽ���ֻط����᡹���������ּ�ת������ն��$n��$l",
        "dodge" : 10,
        "damage": 55,
        "damage_type":  "����"
]),
([      "action":"$N����$w�й�ֱ����һʽ��ˮ�����š���������Ϣ�ض�׼$n��$l�̳�һ��",
        "dodge" : 35,
        "damage": 160,
        "damage_type":  "����"
]),
([      "action":"$N����ȫ��������ע��$w�Ƴ�����â��һʽ��ն����ħ������$n��$l",
        "dodge" : 60,
        "damage": 155,
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
	object ob;

	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	if( (int)me->query("max_force") < 100 )
		return notify_fail("��������������޷���ϰ��Ħ������\n");
	if( (me->query_skill("dacheng-fofa",1) <= 50)
	|| (me->query_skill("damo-sword",1) >= me->query_skill("dacheng-fofa",1)) )
		return notify_fail("��Ĵ�ɷ���Ϊ�������޷���ϰ��Ħ������\n");

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
		return notify_fail("�����������������û�а취��ϰ��Ħ������\n");
	me->receive_damage("kee", 30, "tire");
	me->add("force", -3);
	write("�㰴����ѧ����һ���Ħ������\n");
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
	"���$n�����е�$v����$N��$w��\n",
});

string *unarmed_parry_msg = ({
	"$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
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
	return CLASS_D("shaolin") + "/damo-sword/" + action;
}
