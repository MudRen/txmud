// feilong-quan.c
// ��������ȭ��(Ѳ��ר��)

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":
"$Nһʽ������̽�项��˫ȭ��һ������ĽǶ����������$n��$l",
                "dodge":                -30,
                "parry":                50,
                "force":                90,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һת��һ�С������ڡ���ȭ���¶�������$n��$l",
                "dodge":                -40,
                "parry":                100,
                "force":                110,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N˫��һ�٣�һ�С�������ʳ�����˴�ȭ����$n��ǰ�������֮�ƻ���$n��$l",
                "dodge":                -30,
                "parry":                120,
                "force":                160,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N��һת������$n��ʹ�����乭���¡���������$n��$l�ͻ�",
                "dodge":                -50,
                "parry":                200,
                "force":                190,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
       return 0;
}

int valid_enable(string usage) { return usage=="unarmed"; }

int effective_level() {return 15;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	return 0;
}

string *parry_msg = ({
	"$n����һ����������ճ��$N��$w��һ����\n",
	"$n����΢΢һ�࣬�Ѷ㿪$N�Ĺ��ơ�\n",
	"$nһ�С�ǳ�������������˷���������$N���Ƶ�$N�����Ա���\n",
});

string *unarmed_parry_msg = ({
        "$nһ�С�ǳ�������������˷���������$N���Ƶ�$N�����Ա���\n",
        "$n˫ȭ���䣬��סȫ��Ҫ����\n",
});

string query_parry_msg(object weapon)
{
	return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
	return CLASS_D("npc_skill") + "/feilong-quan/" + action;
}

