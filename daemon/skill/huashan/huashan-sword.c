// huashan huashan-sword.c ��ɽ����

inherit SKILL;

mapping *action = ({
([      "action":"$Nʹһʽ������ӭ�͡�������$w����΢�񣬻ó�һ���������$n��$l",
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "����"
]),
([      "action":"$N����ǰ��ʹ�����Űز��졹�������������ޣ�$w��������$n��$l��ȥ",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "����"
]),
([      "action":"$Nһʽ���ٻ����ա�������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "����"
]),
([      "action":"$N��������Ծ��һʽ�����ƹ�ɽ�����������ּ�ת������ն��$n��$l",
        "dodge" : 10,
        "damage": 55,
        "damage_type":  "����"
]),
([      "action":"$N����$w�й�ֱ����һʽ��������¡���������Ϣ�ض�׼$n��$l�̳�һ��",
        "dodge" : 35,
        "damage": 160,
        "damage_type":  "����"
]),
([      "action":"$N����$wбָ���죬��â���£�һʽ��ɽɽ��𡹣���׼$n��$lбб����",
        "dodge" : 5,
        "damage": 45,
        "damage_type":  "����"
]),
([      "action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ��ˮ������������$n��$l",
        "dodge" : 60,
        "damage": 155,
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_force") < 20 )
		return notify_fail("�������������û�а취������ɽ��������\n");

	if( (string)me->query_skill_mapped("force")!= "zixia-force")
		return notify_fail("��ϰ����ɽ����������Ҫ����ϼ�񹦡���ϡ�\n");

	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�����������ɽ��������\n");
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
	if( (int)me->query("kee") < 30
	|| (int)me->query("force") < 30 )
		return notify_fail("�����������������û�а취��ϰ����ɽ��������\n");

	me->receive_damage("kee", 20);
        me->add("force", -3);

	write("�㰴����ѧ����һ�黪ɽ������\n");
	return 1;
}

int effective_level() { return 12;}

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
        return CLASS_D("huashan") + "/huashan-sword/" + action;
}
