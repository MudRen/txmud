// huashan dugu-sword.c

#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N�����й������Ƕ��¾Ž�����ʽ���������ɡ�������$w�ó�������â��",
                "dodge":                -20,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����ƫ�棬һ�С��뽣�繳�������е�$w����˿˿�������ֶ�����",
                "dodge":                20,
                "damage":               60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���潣ת��һ�С����������������α�������$w�������콣Ӱ��$n������ȥ��",
                "dodge":                30,
                "damage":               60,
                "damage_type":  "����"
        ]),
     ([      "action":               
"$N����$w����һ�ڣ�һʽ���ƽ���������׼$nӭ��һ��",
                "dodge":                -40,
                "damage":		80,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�����������������$wһ�С�������졹��׼$nбб����һ��",
                "dodge":                -40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������������������һ�С��򽣹��ڡ�����$w�бƳ�����������Ϯ��$n��",
                "dodge":                40,
                "damage":               80,
                "damage_type":  "����"
        ]),
    });

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취�����½�����\n");

	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("����Ҳ���аѽ����аɣ�\n");
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
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("�����������������û�а취��ϰ���¾Ž���\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ����½�����\n");
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/dugu-sword/" + action;
}
 
int effective_level() { return 11;}
int effective_parry_level() { return 13; }

string *parry_msg = ({
        "$nʹ��һ�С�����ʽ�������е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$nʹ�����ƽ�ʽ������$N��$w�������⡣\n",
        "$nʹ��һ�С��򽣹��ڡ������е�$v��������ѩӰ��������$N��$w��\n",
        "$n���е�$vһ����һ�С��ı��޽�������$N��$w��������ȥ��\n",
});
string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С�����ʽ������������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С��ƽ�ʽ����$vֱ��$N��˫�֡�\n",
        "$n�����е�$v���������������ȵ�$N�������ˡ�\n",
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
        return -40;
}
int practice_bonus()
{
        return -70;
}
int black_white_ness()
{
        return 0;
}
