// fenghui-sword.c ���ѩ�轣
// by dicky

#include <ansi.h>
inherit SKILL;

string  *msg = ({
"$N����$wбָ���£�������ָ������ָ��������һ�����壬�ն���ȭ���ֽ�Ĵָ�������
��ʳָ��������ָȫչ����������Ĵָ����ʳָ��������ָ��Ȼ������$w���Ⱪ������
$n��$l��ȥ",
"$Nչ�����ƣ����潣�ߣ����һ�գ��ұ�һ�䣬ԽתԽ�����͵�$w���Ⱪ����һ�С����
ɨ��Ҷ����$n$l��ȥ",
"$N����$wٿ�ش̳���һ���彣��ÿһ���Ľ��нԲ�Ȼ�й��⡣�������ӣ��ڲ���䣬����
���������ޡ�",
"$N����š��������˫ָ���˸�ָ�������ֻ�$w����ö��ϣ�һʽ�����·ת��������
��ƥ��������$n��$l",
"$N�ὣ˳�̣�������������������޲��ǽ��������ţ����淵�ӹ��棬�Ѳ����κ�����",
"$N����һ�㣬���κ󳷣���Ȼ��������ǰ����������翾��죬һ�С���������$w��Ʈ
Ʈ��ֱ��$n", 
"$N��������֮����������ɽ������ͺ�һ�����������ǽ�Ӱ������ǧ����������$n�����
��",
"$Nʹ�������¥̨����$wбָ���ϣ�����ֱ��ȴ��������������ش���$n��$l", 
"$N������磬�޿ɵ��棬$n�����и����������纣��һ�㣬һ��һ������ӿ�������Ӳ���",
});

int valid_enable(string usage)
{ return usage=="sword" || usage=="parry"; }

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("��������������޷��������ѩ�轣��\n");

	if(me->query_skill("taxue-force", 1) < 30)
		return notify_fail("���̤ѩ����Ϊ�������޷��������ѩ�轣��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i;
        i = random(me->query_skill("fenghui-sword"))/5;

        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(50)+i),
                "dodge": random(10)+5,
                "damage_type":random(2)?"����":"����",
        ]);
}

int practice_skill(object me)
{
        object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("kee") < 50)
		return notify_fail("������������������˷��ѩ�轣��\n");
	me->receive_damage("kee", 35,"tire");
	return 1;
}

int effective_level() { return 12;}
//int effective_parry_level() { return 12; }

string perform_action_file(string action)
{
        return CLASS_D("taxue") + "/fenghui-sword/" + action;
}

string *parry_msg = ({
	"$n������$v�û�����ǽ���赲ס��$N��$w��\n",
	"$n�����е�$v����Ƿ��겻͸����ס��$N�Ĺ��ơ�\n",
});
string *unarmed_parry_msg = ({
	"$n�����е�$v����Ƿ��겻͸����ס��$N�Ĺ��ơ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}