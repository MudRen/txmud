// canhe-zhi.c from mool

inherit SKILL;

mapping *action = ({
([      "action" : "$N������ָ���أ�Сָ�͵ص���$n���ؿ�ҪѨ��ȴ��һ�С�����ͨ�̡�",
        "damage":50,
        "damage_type" : "����"
]),
([      "action" : "$N����Сָ���˸�С���ߣ����Ż���$n��$l,��һ�С��岨���ۡ�",
        "damage":60,
        "damage_type" : "����"
]),
([      "action" : "$Nת���ͷ��һʽ��̫�׺��������������ָ���ּ���$n��$l",
        "damage":70,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ���ƺ�֮�ɡ�����������ָ��ƮƮ�ص���$n��$l",
        "damage":80,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ�С��ر�ɽ�ݡ���������ָ������Ȧ������$n��������ʮ��Ѩ",
        "damage":85,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ�С��������̡�������������Ȧ��������ָͻȻ��Ȧ�д�����ֱ��$n��$l",
        "damage":90,
        "damage_type" : "����"
]),
([      "action" : "$N����ʳָ�������㣬�������$n�ı��Ĵ�Ѩ��ȴ��һʽ������ʯջ��",
        "damage":95,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�����ָ��ߡ�����ʳָ�������$n���ؿڣ���$n�ؿڵ����д�Ѩ��������ָ��֮��",
        "damage":100,
        "damage_type" : "����"
]),
([      "action" : "$N����Ĵֱָ����ңң����$nһ�࣬һ������ֱ��$n��ȥ����һʽ���������ա�",
        "damage":105,
        "damage_type" : "����"
]),
([      "action" : "$N���һ��������Ĵָ����$n�������ɵ���ȴ��һʽ���������¡�",
        "damage":110,
        "damage_type" : "����"
])

});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���κ�ָ������֡�\n");
        if ((int)me->query_skill("jinghai-force", 1) > 80 ||
            (int)me->query_skill("unarmed", 1) > 10)
                return 1;
        else
                return notify_fail("��ľ����񹦻�򲻹����޷�ѧ�κ�ָ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if((int)me->query("kee")<30)
                return notify_fail("�������̫���ˡ�\n");
        if((int)me->query("force")<25)
                return notify_fail("��������������κ�ָ��\n");
        me->receive_damage("kee",25);
        me->add("force",-10);
        return 1;
}

string perform_action_file(string action)
{
return CLASS_D("jinghai") +"/canhe-zhi/" + action;
}

string *parry_msg = ({
	"$nһ�С�Ҹ��͵�ҡ���˫������$N��$w������\n",
});

string *unarmed_parry_msg = ({
	"$n˫ȭ������һ�С�������ˮ����������$N�Ĺ��ơ�\n",
});

int effective_level() { return 12;}

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
