// jinghong-sword.c
// ��꾪�轣��

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nһ�С����ճ�����������$w������̣�˲����бб�Ĵ���n��$l",
                "dodge":                -10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ���ġ��������ס������е�$w�����һƬ��������$n��$l",
                "dodge":                10,
                "damage":               60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ����������衹������$w΢΢��������綾�߰����$n��$l",
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w��һʽ�����ĸ�ȼ�������α�������$w�Կ�������$n��$l��",
                "dodge":                40,
                "damage":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���е�$w��Ȼ����˼��Ĵ̳���һ�С�������С�����һ������ĽǶ�����$n����",
                "dodge":                30,
                "damage":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһʽ�����ӵ�к�������е�$wһ����������$n��$l",
                "dodge":                60,
                "damage":               130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһʽ��ج�ξ��꡹�����е�$w��Ϊһ������Ľ��⣬����$n��$l",
                "dodge":                30,
                "damage":               60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С��������项���������е�$w��˫������$n����$wȴ�������������$n��$l",
                "dodge":                -30,
                "damage":               140,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 30 )
                return notify_fail("�������������û�а취������꾪�轣������\n");

        if( (string)me->query_skill_mapped("force") != "suiyu-force")
                return notify_fail("����꾪�轣����������ϡ������޷��ķ�����������\n");

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
	if( (me->query("kee") < 40)
	|| (me->query("force") < 10) )
		return notify_fail("�����������������û�а취��ϰ����꾪�轣������\n");
	me->receive_damage("kee", 30,"tire");
	me->add("force", -5);
	write("�㰴����ѧ����һ�顺��꾪�轣������\n");
	return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("rain") + "/jinghong-sword/" + action;
}
 
int effective_level() { return 12;}

string *parry_msg = ({
        "$nʹ��һ�С��÷���꡹�����е�$v��μ��У��������������ɡ�\n",
        "$nʹ����Ʈ�����꡹�����е�$v��$N��$wһһ���⡣\n",
        "$nʹ��һ�С�����б���������е�$v����һ�У���ס��$N��$w��\n",
        "$n���е�$v���һƬ��Ļ��һ�С��������ա��ص��ܲ�͸�硣\n",
});

string *unarmed_parry_msg = ({
        "$n���е�$v��Ϊһ����⣬������$N��\n",
        "$nһʽ��Ƽˮ������������бб��Ʈ�����ɡ�\n",
        "$nʹ��һ�С�����������������$v��$N�������к�����бƮ������\n",
        "$n�����������Σ����Ȱ�ĺ�Ȼ��ʧ�ˡ�\n",
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
