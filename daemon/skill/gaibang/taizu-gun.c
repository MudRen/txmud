// taizu-gun.c ̫�����
// by pian

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": HIG"$Nһʽ"+WHT"��ϸ��΢�簶��"+HIG"������$w"+HIG"�ó�һƬ��Ӱ����$n��$l"NOR,
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "����"
]),
([      "action": HIG"$N����ǰ����͸$w"+HIG"������һʽ"+WHT"��Σǽ��ҹ�ۡ�"+HIG"����Ӱ�����$n��$l��ȥ"NOR,
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "����"
]),
([      "action": HIG"$Nһʽ"+WHT"���Ǵ�ƽҰ����"+HIG"������Ʈ�����ߣ�����$w"+HIG"ȴ����$n��$l"NOR,
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "����"
]),
([      "action": HIG"$N��������Ծ��һʽ"+WHT"����ӿ������"+HIG"����ӰƮƮ��ת������ն��$n��$l"NOR,
        "dodge" : 10,
        "damage": 55,
        "damage_type":  "����"
]),
([      "action": HIG"$N����$w"+HIG"�й�ֱ����һʽ"+WHT"��������¡�"+HIG"��������Ϣ�ض�׼$n��$l�̳�һ��"NOR,
        "dodge" : 35,
        "damage": 160,
        "damage_type":  "����"
]),
([      "action": HIG"$N����$w"+HIG"бָ��һʽ"+WHT"��ƮƮ�����ԡ�"+HIG"����׼$n��$lбб����"NOR,
        "dodge" : 5,
        "damage": 45,
        "damage_type":  "����"
]),
([      "action": HIG"$N��ָ�����㣬����$w"+HIG"һʽ"+WHT"�����һɳŸ��"+HIG"����$n��$l"NOR,
        "dodge" : 60,
        "damage": 155,
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_force") < 20 )
		return notify_fail("�������������û�а취����̫���������\n");

	if( (string)me->query_skill_mapped("force")!= "taizu-force")
		return notify_fail("��ϰ��̫�����������Ҫ��̫���ķ�����ϡ�\n");

	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "stick" )
		return notify_fail("���������һ�����Ӳ�������̫���������\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	|| (int)me->query("force") < 30 )
		return notify_fail("�����������������û�а취��ϰ��̫���������\n");

	me->receive_damage("kee", 20);
        me->add("force", -3);

	write("�㰴����ѧ����һ��̫�������\n");
	return 1;
}

int effective_level() { return 10;}

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
        return CLASS_D("gaibang") + "/taizu-gun/" + action;
}
