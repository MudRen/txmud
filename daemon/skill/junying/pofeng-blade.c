// pofeng_blade.c

inherit SKILL;
mapping *action = ({
        ([      "action":               "$Nʹһ�С�Ҫ��С����������$w���Ƶ���$n��$lնȥ��",
                "damage":               180,
                "dodge":                70,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�䵶���£�$w����һ�С��������ˡ����¶�������$n��$l",
                "damage":               160,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����һת��һ�С�����ƴ�ˡ�$w���籩������$n��$l",
                "damage":               140,
                "damage_type":  "����"
        ]),

});

int valid_learn(object me)
{
        return 0;
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
        return 0;
}

int effective_level() { return 15;}

string *parry_msg = ({
        "$nʹ��һ�С�������䡹�������е�$v����$N����ָ��\n",
        "$n���е�$vһ�������һƬ��������籩�������$N��ȫ��\n",
        "$n΢��һ�������е�$v����һ���⻡����$N��ȫ��Χס��\n",
});

string *unarmed_parry_msg = ({
"$nʹ��һ�С�Ҫ��С�����������е�$v����$N��\n",
"$n���̤ǰ̤�����е�$vֱ����$N֮�ؾȡ�\n",
"$n���е�$v����һ�С����겻͸������$N��ȫ��Χס��\n",
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
        return 40;
}

int practice_bonus()
{
return 5;
}

int black_white_ness()
{
        return 20;
}