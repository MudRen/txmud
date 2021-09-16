// qimen-blade
// by dicky

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ����Х������$wһ��������⻯����㷱�ǣ���$n��$l��ȥ",
        "dodge" : 5,
        "force": 50,
        "damage_type" : "����"
]),
([      "action" : "$N���һ�������С���һ�С�����ǵ���׳־�����������϶�����$n��$l��ȥ",
        "dodge" : 10,
        "force": 60,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��䵶��ת��Ǭ����������$w�ڿ��м���ת����Ȧ������$n��$l",
        "dodge" : 0,
        "force": 70,
        "damage_type" : "����",
]),
([      "action" : "$N��ɫ��ɱ��һ���������е�����˸������һƬ�̹ǵĵ��罫$n����Χס!",
        "dodge" : 10,
        "force": 80,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int effective_level() { return 12;}

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("gaibang-force", 1) < 30)
                return notify_fail("���ؤ���ķ�ѧϰ�û�������\n");
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
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("kee") < 30 || (int)me->query("force") < 15 )
                return notify_fail("�����������������û�а취��ϰ���ŵ�����\n");
        me->receive_damage("kee", 30, "tire");
        me->add("force", -15);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("gaibang") + "/qimen-blade/" + action;
}

string *parry_msg = ({
	"$n������$v�û�����ǽ���赲ס��$N��$w��\n",
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