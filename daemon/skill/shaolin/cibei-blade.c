// cibei-blade.c �ȱ���
// �ع����ҷ�ȱ� cibei (�����˵�����ʹ busy)

inherit SKILL;

mapping *action = ({
([      "action" : "$N��������һ��������$wбָ��һ�С����˹۳�����һ����$n��$l��ȥ",
        "force" : 120,
        "dodge" : -10,
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ���������ˡ�������$w��ת���õ�������$n��$l��",
        "dodge" : -10,
        "damage" : 45,
        "damage_type" : "����"
]),
([      "action" : "$N����һ��������$w������һ�С������׺���������$n��$l",
        "damage" : 45,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ż�ɽ����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
        "damage" : 25,
        "damage_type" : "����"
]),
([      "action" : "$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
        "force" : 180,
        "dodge" : 20,
        "damage" : 60,
        "damage_type" : "����"
]),
});

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("���������һ�ѵ�������ѧϰ�ȱ�����\n");

	if(me->query_skill("cibei-blade",1) >= me->query_skill("dacheng-fofa",1)
	|| (int)me->query_skill("dacheng-fofa", 1) < 30)
		return notify_fail("��Ĵ�ɷ���Ϊ�������޷���ϰ�ȱ�����\n");
	return 1;
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
	object weapon;
	if( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade" )
		return notify_fail("���������һ�ѵ���������ϰ�ȱ�����\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("���������֧����������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("kee", 40,"tire");
	return 1;       
}

int effective_level() { return 10;}

string *parry_msg = ({
	"$n����һ�Σ������е�$v����$N����ָ��������$N�Ĺ��ơ�\n",
	"$n���˷��������е�$vֱ��$N��$w��˫�֣�������$N�Ĺ��ơ�\n",
});

string *unarmed_parry_msg = ({
	"$n����һ�Σ������е�$v����$N����ָ��������$N�Ĺ��ơ�\n",
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
        return -20;
}

string perform_action_file(string action)
{
	return CLASS_D("shaolin") + "/cibei-blade/" + action;
}
