// lianhuan-chui.c ��������

inherit SKILL;

mapping *action = ({
([      "action":"$N����$wһ������������һ�����죬һ�С�����������������$n��$l",
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "����",
]),

([      "action":"$N����ǰ������$w��Բ������$n��$l������ȥ",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "����",
]),
([      "action":"$Nһʽ��̩ɽѹ����������$w����������$n��������",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "����",
]),

});

int valid_learn(object me)
{
	return 0;
}

int valid_enable(string usage)
{
	return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	return 0;
}

int effective_level() { return 12;}

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
	return CLASS_D("npc_skill") + "/lianhuan-sword/" + action;
}
