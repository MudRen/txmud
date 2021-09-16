// qiuyue-fork.c
#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "name":                 "��ѻ����",
                "action":               "$Nʹһ�С���ѻ���¡�������$w�������ϣ�������$n��$l",
                "dodge":                20,
                "damage":               100,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�������",
                "action":               "$N����һת��һ�С�������֡�$w����һ�Ź�Ӱ������$n��$l",
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�������",
                "action":               "$N���β�����һ�С�������š�����$w������Ϣ�Ĵ���$n��$l",
                "dodge":                -30,
                "damage_type":  "����"
       ]),
        ([      "name":                 "��Ҷ���",
                "action":               "$N�͵�����һ��������$wһ����ʹ������Ҷ�����ɨ��$n������",
                "dodge":                -10,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���ɨ��Ҷ",
                "action":               "$Nʹ��һ�С����ɨ��Ҷ������$w���籩��㣬��$n��$l��ȥ",
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "name":                 "����δ��",
                "action":               "$N����$w����������;һ�䣬һ�С�����δ������$n��$l��ȥ",
                "damage":               150,
                "damage_type":  "����"
        ]),
});
int valid_learn(object me)
{
 object ob;
        if( (int)me->query("max_force") < 30 )
                return notify_fail("�������������û�а취������ǹ����\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "fork" )
                return notify_fail("���������һ��ǹ������ǹ����\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="fork" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 10 )
                return notify_fail("�����������������û�а취��ϰ����ǹ����\n
");
        me->receive_damage("kee", 50);
        me->add("force", -10);
        write("�㰴����ѧ����һ������ǹ����\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{

}

int effective_level() { return 15;}

string *parry_msg = ({
        "$nʹ��һ�С�"+HIB"�������ٱ��"NOR+"��������$v����������ס��$N�Ĺ��ơ�\n",
        "$nһ�����е�$v��ʹ��һ�С�����������"NOR+"�������е�$v��ס��ȫ��\n",
        "$n��$v������һ�㣬$v�����������պ�ֱ��$N��˫�ۡ�\n",
});
string *unarmed_parry_msg = ({
        "$nʹ��һ�С�"+HIB"�������ٱ��"NOR+"��������$v����������ס��$N�Ĺ��ơ�\n",
        "$nһ�����е�$v��ʹ��һ�С�"+HIB"����������"NOR+"�������е�$v��ס��ȫ��\n",
        "$n��$v������һ�㣬$v�����������պ�ֱ��$N��˫�ۡ�\n",
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
        return 5;
}
int practice_bonus()
{
        return 5;
}
int black_white_ness()
{
        return  15;
}
string perform_action_file(string action)
{
        return CLASS_D("junying") + "/qiuyue-fork/" + action;
}
