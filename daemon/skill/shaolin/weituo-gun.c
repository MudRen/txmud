// weituo-gun.c Τ�ӹ�
// �ع���Τ�ӽ�ħ xiangmo

inherit SKILL;

mapping *action = ({
([      "action":"$N����һ�С�߳����ơ���$w����һ���������$n����ȥ��",
        "damage": 40,
        "damage_type":"����"
]),
([      "action":"$N����Ծ������$w����һ�ߣ�һ�С��������ء����͵���$n��$l��ȥ",
        "damage": 65,
        "damage_type":"����"
]),
([      "action":"$Nһ�С��ڸ����ơ�������$w���ŷ�����$n����ͷ��������ȥ��",
        "damage": 80,
        "damage_type":"����"
]),
([      "action":"$N����һ��������һ�С��������¡�������$wЮ��������Ѹ��ɨ��$n��$l",
        "force" : 250,
        "dodge" : 15,
        "parry" : 5,
        "damage": 25,
        "damage_type":"����"
]),
([      "action":"$N˫�ֳֹ����˸���ش�Ȧ��һ�С���ϼ���ա���һ����Բ�����л�����ײ��$n���ؿ�",
        "damage": 95,
        "damage_type":"����"
]),
([      "action":"$N��͸$w��һ�С�������ˡ���������ֱ��$n��$l",
        "damage": 50,
        "damage_type":"����"
]),
});

int valid_learn(object me)
{
	object weapon;
	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "stick")
		return notify_fail("���������һ�����ӣ�����ѧϰΤ�ӹ���\n");
	if((int)me->query("max_force") < 100)
		return notify_fail("�������̫�ͣ��޷�ѧϰΤ�ӹ���\n");
	if(me->query_skill("weituo-gun",1) >= me->query_skill("yiqi-force",1))
		return notify_fail("��Ļ�Ԫһ���������������޷�ѧϰΤ�ӹ���\n");

        return 1;
}

int valid_enable(string usage)
{
	return (usage=="stick") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 40 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 25,"tire");
	return 1;
}

int effective_level() { return 10;}

string *parry_msg = ({
        "$n����$v����$N��$w��������$N��$w��\n",
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
        return -10;
}

string perform_action_file(string action)
{
	return CLASS_D("shaolin") + "/weituo-gun/" + action;
}
