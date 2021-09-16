// lianhua-zhang.c ������
// by dicky

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N���Ʈ������ת��������һ�С����������ߡ������������б����쬵�һ����������$n��$l",
        "dodge" : -10,
        "force": 50,
        "damage_type": "����"
]),

([  "action": "$N����һʽ��ˮ�����Ƶ������������б��������һ��΢�縧��$n��$l������˿������",
        "dodge" : -5,
        "force": 60,
        "damage_type": "����"
]),

([      "action": "$N΢΢һЦ�����ư���$n��$l�������ơ�����ˮ������֮�����������С���������䬡�",
        "dodge" : -10,
        "force": 70,
        "damage_type": "����"
]),

([  "action": "$Ņ��ͷ����Ŀ��ת˲����$n���ӣ�������ƮƮһת��ƽɳ��δû���������������ĳ�",
        "dodge" : -10,
        "force": 80,
        "damage_type" : "����"
]),

([  "action": "$N�������Ʈ����һʽ���������ˮ�����������������ƣ���˿����ƹ�$N��������Ȼ��$n��$lϮȥ",
        "dodge" : -15,
        "force": 80,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) 
{ return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʊ�����֡�\n");
        if ((int)me->query_skill("gaibang-force", 1) < 30)
                return notify_fail("���ؤ���ķ���򲻹����޷�ѧ�����ơ�\n");
        if ((int)me->query("max_force") < 400)
                return notify_fail("�������̫�����޷��������ơ�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 35)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 15)
                return notify_fail("������������������ơ�\n");
        me->receive_damage("kee", 35);
        me->add("force", -15);
        return 1;
}

int effective_level() { return 11;}

string perform_action_file(string action)
{
	return CLASS_D("gaibang") +"/lianhua-zhang/" + action;
}

string *parry_msg = ({
        "$nһ�С����ҽ𹳡���˫������$N��$w������\n",
        "$n˫������ܲ�͸�磬һ�С�ֱ������������$N��$w��\n",

});

string *unarmed_parry_msg = ({
        "$n˫��һ�죬һ�С�������ӿ����������$N�Ĺ��ơ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
