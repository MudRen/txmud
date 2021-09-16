// xianglong-zhang.c ����ʮ����
// by dicky

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N˫��΢����˫��ƽƽ�ᵽ��ǰ���ұۻ���ԲȦ������һ����һ�С�"HIY"�����л�"NOR"������$n",
        "dodge": 10,
        "damage": 40,
        "lvl" : 30,
        "damage_type": "����"
]),
([      "action": "$NͻȻ�����գ�������ת��˫�ƾӸ�����һ�С�"HIY"��������"NOR"��ֱ�����µ�$nѹȥ",
        "dodge": -5,
        "damage": 45,
        "lvl" : 40,
        "damage_type": "����"
]),
([      "action": "$Nһ��δ�꣬һ���������ƻ��գ���������һ�С�"HIY"��������"NOR"����Ѹ���ޱȵ�����$n��$l",
        "dodge": -10,
        "damage": 50,
        "lvl" : 50,
        "damage_type": "����"
]),
([      "action": "$N���������˫������ƽ�ƣ�ʩ�����С�"HIY"�轥��½"NOR"���������д���������������$n",
        "dodge": -5,
        "damage": 55,
        "lvl" : 60,
        "damage_type": "����"
]),
([      "action": "$N���ƾ۳�ȭ״����$n�ֱۣ�����������ǰ��һ�С�"HIY"Ǳ������"NOR"������������ѹ��$n",
        "dodge": -10,
        "damage": 60,
        "lvl" : 70,
        "damage_type": "����"
]),
([      "action": "��������$N������ǰ����������һ�С�"HIY"�����"NOR"�����������Ʒ��絶������$n��$l",
        "dodge": 5,
        "damage": 65,
        "weapon" : "�������Ʒ�",
        "lvl" : 80,
        "damage_type": "����"
]),
([      "action": "$N˫���ಢ������ͻȻǰԾ��ʹ����"HIY"ͻ������"NOR"�����У�������ɽ��������$n�����Ƴ�",
        "dodge": 10,
        "damage": 70,
        "lvl" : 90,
        "damage_type": "����"
]),
([      "action": "$N���һ�������Ŵ󿪣�˫��һ��һ��ʹ����"HIY"�𾪰���"NOR"��������һ�е�ն��$n",
        "dodge": -25,
        "damage": 75,
        "lvl" : 100,
        "damage_type": "����"
]),
([      "action": "$N��ǰһ����һ�С�"HIY"��Ծ��Ԩ"NOR"��������˫����$n�����ĳ����Ʒ�������������ɳʯ",
        "dodge": -10,
        "damage": 80,
        "lvl" : 120,
        "damage_type": "����"
]),
([      "action": "$N������ǰ�ƶ���˫�Ʒ�ʹ��ʽ��"HIY"˫��ȡˮ"NOR"�����������Ʒ�һ��һ��ͬʱѹ��$n$l",
        "dodge": -10,
        "damage": 85,
        "lvl" : 140,
        "damage_type": "����"
]),
([      "action": "$N���΢�������η����ڰ�����ĳ���"HIY"��Ծ��Ԩ"NOR"����˫������������$n��$l����",
        "dodge": -5,
        "damage": 90,
        "weapon" : "����",
        "lvl" : 160,
        "damage_type": "����"
]),
([      "action": "$N��������ʹ���С�"HIY"ʱ������"NOR"����˫��һ��һ����$n���������������ҿ���ʮ����",
        "dodge": -10,
        "damage": 95,
        "lvl" : 180,
        "damage_type": "����"
]),
([      "action": "$Nʹ��һ�С�"HIY"���Ʋ���"NOR"�������������ĳ�����ס$n����·������бб����������$l",
        "dodge": -10,
        "damage": 100,
        "weapon" : "����������",
        "lvl" : 200,
        "damage_type": "����"
]),
([      "action": "$N������ǰ��һ�С�"HIY"��������"NOR"����˫�ƿ��������������$n�������ϵ�ɳʯȴ��������",
        "dodge": -15,
        "damage": 105,
        "lvl" : 220,
        "damage_type": "����"
]),
([      "action": "$N����һת��ͻȻ����$n��ǰ�����ƻ�������һ�С�"HIY"��ս��Ұ"NOR"������Ȼ����$n��$l",
        "dodge": -5,
        "damage" : 20,
        "damage": 110,
        "weapon" : "��Ե",
        "lvl" : 240,
        "damage_type": "����"
]),
([      "action": "$Nһ�����ȣ���ǰ�Ż��󿪣�˫���ಢ������$n�͵���ȥ������һ�С�"HIY"��˪����"NOR"��",
        "dodge": -25,
        "damage": 115,
        "lvl" : 260,
        "damage_type": "����"
]),
([      "action": "$N���Ƶʹ�������̧�ߣ�ʹ��һ�С�"HIY"����ެ"NOR"���������ۻ������ͬʱ���м��$n��ѹ��ȥ",
        "dodge": 5,
        "damage": 120,
        "lvl" : 280,
        "damage_type": "����"
]),
([      "action": "����$N���ƻ��أ������ת�����ƽ�����һ�ڣ�һ�С�"HIY"������β"NOR"����������$n",
        "dodge": 15,
        "damage": 125,
        "lvl" : 300,
        "damage_type": "����"
]),
});

int valid_enable(string usage) 
{ return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ʮ���Ʊ�����֡�\n");

        if ((int)me->query_skill("gaibang-force", 1) < 100)
                return notify_fail("���ؤ���ķ���򲻹����޷�������ʮ���ơ�\n");

        if( me->query("gender") == "������")
                return notify_fail("��һ�����в�Ů֮������ѧϰ�����ƣ�\n");

        if ((int)me->query("max_force") < 2000)
                return notify_fail("�������̫�����޷�ѧ����ʮ���ơ�\n");

        if ((int)me->query_str() < 100 )
                return notify_fail("��û����׳�ı����޷�ѧ����ʮ���ơ�\n");

        if ((int)me->query_con() < 60)
                return notify_fail("��û���ۺ�������޷�ѧ����ʮ���ơ�\n");

        return 1;
}

mapping query_action(object me, object weapon)
{

        return action[random(sizeof(action))];
/*
        int i,level,n;

        level = (int) me->query_skill("xianglong-zhang",1);

        n = sizeof(action);
        for(i=0;i<n;i++)
                if(level >= action[i]["lvl"])
                        return action[random(i)];
*/
} 

int practice_skill(object me)
{
        int lvl = (int)me->query_skill("xianglong-zhang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("gin") < 20)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 30)
                return notify_fail("�����������������ʮ���ơ�\n");

        me->receive_damage("jingli", 20);
        me->add("force", -30);
        return 1;
}

int effective_level() { return 12;}

string perform_action_file(string action)
{
	return CLASS_D("gaibang") +"/xianglong-zhang/" + action;
}

string *parry_msg = ({
"$p�����������С�"HIY"������β"NOR"�������Ʒ�����$P���������׺ݣ�����Ӳ�ӣ�����ܿ���\n",
"ֻ��$p����Բ��������ֱ�ƣ�������ǰ��һ�д��Ƿ�����ȴ����˫��֮�䲼��һ����ڡ�\n",
"$p���²��ҵ�����˫�Ƶ���ƽ�ƣ����Լ�ȫ������������֮�¡��ص�����Ԩͣ���ţ�ֱ�ް��������\n",
});

string *unarmed_parry_msg = ({
        "$n��������ʹ���С������Ҷ����������$N�Ĺ��ơ�\n",
});


string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
