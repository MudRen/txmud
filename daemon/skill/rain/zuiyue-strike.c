// zuiyue-strike.c
// ����������

inherit SKILL;
mapping *action = ({
        ([      "action":               
"$Nһʽ�����·ɻ���������һ���������У�Ϯ��$n����·�����ƽ������Ϯ��$n����·",
                "dodge":                -100,
                "parry":                100,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ƻ�����Բ����ס��·���������ƣ�ʹ����Բ���ڻ���������$n��$l",
                "dodge":                -100,
                "parry":                100,
                "force":                 70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��黨���¡���ң��һָ��һ����绮�ն�������$n����",
                "dodge":                -100,
                "parry":                100,
                "force":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�����ٿմ���һʽ���������桹���������ĳ��ڣ��������ĳ��⣬�ֹ�$n�ϣ��У�����·",
                "dodge":                -100,
                "parry":                100,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�����˶�������������ɣ�ʹ�����������᡹����$n��$l�ĳ�һ���ƾ��硣",
                "dodge":                -100,
                "parry":                100,
                "force":                140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ��ǰ��һ�С�����б��������ֻ���Ƽ�����װ���$n��$l��������",
                "dodge":                -200,
                "parry":                200,
                "force":                150,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�������������ơ�������֡�\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
	return CLASS_D("rain") + "/zuiyue-strike/" + action;
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if(me->query("force") < 10)
		return notify_fail("���������������Ϣһ�������ɡ�\n");
	me->add("force", -5);
	me->receive_damage("kee", 25,"tire");
	write("�㰴����ѧ����һ�顺���������ơ���\n");
        return 1;
}

int effective_level() { return 12;}
 
string *parry_msg = ({
        "$nʹ��һ�С�ܷܷ���ơ�������������ɨ������һ�����������ȥ��\n",
        "$n˫������ܲ�͸�磬һ�С���������������$N��$w��\n",
        "$nʹ��������׷�¡���˫����ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$nһ�С���������������������ɨ������һ�����������ȥ��\n",
        "$nʩչ����������꡹�����赭д�Ļ�����$N�Ĺ��ơ�\n",
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

