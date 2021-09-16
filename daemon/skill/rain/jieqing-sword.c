// jieqing-sword.c
// ���齣��

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nһ�С���Ȼ���ˡ�����ʱ����$w����Ʈ�磬Ѹ����������n��$l",
                "dodge":                -10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ���ġ����������������е�$w����һ��ɭ�亮������$n��$l",
                "dodge":                10,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ����������塹��һ�����⣬����һ�ž��磬��ֱ��Ϯ$n��$l",
                "dodge":                -10,
                "damage":               80,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w��һʽ������ֹˮ��һ�����У����缲��Ѹ�꣬����է�������$n��$l��",
                "dodge":                40,
                "damage":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"ֻ�������ݺᣬ����������$Nһ�С�����Ե���԰�ն���$n��������",
                "dodge":                30,
                "damage":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһʽ���䷢���项�����е�$w���ɽ���������ӵ�к��Ю����������֮������$n��$l",
                "dodge":                60,
                "damage":               110,
                "damage_type":  "����"
        ]),
        ([      "action":               
"���ս��������$Nһʽ��������ơ������е�$w��Ϊһ����������ľ��⣬����$n��$l",
                "dodge":                30,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С��˴˲�����������һ����Ϊһ�����⣬����$n��$l",
                "dodge":                -30,
                "damage":               120,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 20 )
                return notify_fail("�������������û�а취�������齣������\n");

        if( (string)me->query_skill_mapped("force") != "suiyu-force")
                return notify_fail("�����齣����������ϡ������޷��ķ�����������\n");

        if( !(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

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
	if( (me->query("kee") < 30)
	|| (me->query("force") < 5) )
		return notify_fail("�����������������û�а취��ϰ�����齣������\n");
	me->receive_damage("kee", 30, "tire");
        me->add("force", -5);
        write("�㰴����ѧ����һ�顺���齣������\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("rain") + "/jieqing-sword/" + action;
}
 
int effective_level() { return 12;}

string *parry_msg = ({
        "$nʹ��һ�С����ͬ���������е�$v����һ����Ļ����ס��$N��$w��\n",
        "$nʹ�������Ʊ����������е�$v��$N��$wһһ�㿪��\n",
        "$nʹ��һ�С����޿����������е�$v���綾�߰��ס��$N��$w��\n",
        "$n���е�$vбб������һ�С�ն���Ե������$N��$w����ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n���е�$v�й�ֱ�̣�ʹ��$N�Ļ����Ա���\n",
        "$nһʽ������ѰԵ���������˺�Ȼ��ʧ�ˡ�\n",
        "$nʹ��һ�С���Ȼ��Ե����$v����Ĳ�����$N��$w��\n",
        "$n�Թ��Ȱ�Ľ����Ƶ�$N�������ˡ�\n",
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
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 15;
}


