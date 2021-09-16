inherit SKILL;

mapping *action = ({
([      "action":"$N����$w΢΢������ǰ�ݳ���һ�С�������¡�������$n��$l",
        "dodge" : -10,
        "damage": 50,
        "damage_type":  "����"
]),
([      "action":"$N����ǰ��ʹ���������¡��������������ޣ�$w����$n��$l",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "����"
]),
([      "action":"$Nһʽ�������ġ������κ�����ң���ʽ�Ĵ��任������$w��$n��ȥ",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "����"
]),
([      "action":"$N��������Ծ������һʽ���������ѡ����������������϶���ն��$n��$l",
        "dodge" : 10,
        "damage": 60,
        "damage_type":  "����"
]),
([      "action":"$N����$w���˸���Բ��ͻȻһʽ�������¡�����׼$n��$l����̳�����",
        "dodge" : 35,
        "damage": 70,
        "damage_type":  "����"
]),
([      "action":"$N�á��¹��������������ɶ�������������$w�������ͻ�֣���������$n��$l",
        "dodge" : 60,
        "damage": 80,
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        if( (int)me->query("max_force") < 100 )
                return notify_fail("��������������޷���ϰ�¹⽣����\n");
        if( ((int)me->query_skill("jinghai-force",1) <= 20 )
        || (me->query_skill("moonlight-sword",1) >= me->query_skill("jinghai-force",1)) )
                return notify_fail("��ľ�������Ϊ�������޷���ϰ�¹⽣����\n");

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
        if( (int)me->query("kee") < 30 || (int)me->query("force") < 3 )
                return notify_fail("�����������������û�а취��ϰ�¹⽣����\n");
        me->receive_damage("kee", 30, "tire");
        me->add("force", -3);
        write("�㰴����ѧ����һ���¹⽣����\n");
        return 1;
}

int learn_bonus()
{
        return -20;
}

int practice_bonus()
{
        return -40;
}

int black_white_ness()
{
        return -10;
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
        return CLASS_D("jinghai") + "/moonlight-sword/" + action;
}

