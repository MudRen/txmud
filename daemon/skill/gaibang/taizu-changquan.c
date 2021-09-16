// gaibang taizu-changquan.c ̫�泤ȭ
// edit pian

#include <ansi.h>
inherit SKILL;
mapping *action = ({
	
([     "action":           HIG"$N˫ȭһǰһ������һ��"+WHT"�����Ԫ�ơ�"+HIG"����$n��$l��"NOR,
              "dodge":             -30,
              "parry":             -70,
              "force":             90,
              "damage_type":       "ץ��"
       ]),
([     "action":            HIG"$N��Ӱһת��˫��һ��"+WHT"�������ġ�"+HIG"ֱ��$n$l��"NOR,
              "dodge":             -10,
              "parry":             -60,
              "force":             160,
              "damage_type":       "����"
       ]),
([     "action":            HIG"$N����һȦ������һ��"+WHT"�����ն��ء�"+HIG"����$n��$l��"NOR,
              "dodge":             -30,
              "parry":             -40,
              "force":             90,
              "damage_type":       "����"
       ]),

([     "action":            HIG"$N˫��һ����һʽ"+WHT"���������š�"+HIG"��׼$n��$lץȥ��"NOR,
              "dodge":             10,
              "parry":             -60,
              "force":             120,
              "damage_type":       "ץ��"
       ]),

([     "action":            HIG"$N�����������ƮƮһ��"+WHT"������������"+HIG"����$n$l��"NOR,
              "dodge":             -20,
              "parry":             -50,
              "force":             90,
              "damage_type":       "����"
       ]),

([     "action":            HIG"$Nʹ��"+WHT"���������꡹"+HIG"���Ծ���׼$n$l�ĳ�һ�ƣ�"NOR,
              "dodge":             -70,
              "parry":             -40,
              "force":             110,
              "damage_type":       "����"
       ]),

([     "action":            HIG"$N������$n$l��������һ��"+WHT"��¶��Ϊ˪��"+HIG"��������ץ����"NOR,
              "parry":             -90,
              "force":             130,
              "damage_type":       "����"
       ]),

([     "action":            HIG"$N���ֵݸ����У�����ʹ��"+WHT"���ٻ����졹"+HIG"����$n��$l��"NOR,
              "parry":             -90,
              "force":             100,
              "damage_type":       "����"
       ]),

});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("\n����Ҫ�������ò�������̫�泤ȭ����\n"NOR);

	if( (int)me->query("max_force") < 20 )
		return notify_fail(HIY"�������̫�����޷�������̫�泤ȭ����\n"NOR);
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
       return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("���������������������ϰ��̫�泤ȭ����\n");
	if( (int)me->query("force") < 100 )
		return notify_fail("�������������������ϰ��̫�泤ȭ����\n");

	me->receive_damage("kee", 25, "tire");
	me->add("force", -3);
	return 1;
}

int effective_level() { return 10; }

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 80 )
		return 0;

	if( random(damage_bonus/2) > victim->query("str") )
	{
		victim->receive_wound("kee", (damage_bonus - 50) / 3 );

		switch(random(5))
		{
			case 0: return "��������������һ�����쪬�����ǹ����������\n";
			case 1: return "$N����һ�ª�$n��$l������������һ�����졣\n";
			case 2: return "ֻ����$n��$l��������һ�� ...\n";
			case 3: return "$N��˫����ͬһ������һ����Ѹ�����׵ػ���$n��$l��\n";
			case 4: return "��ɽ�����ֹ�Ȼ�����鴫��$n��$l���̱�ӡ��һ�ǣ�\n";
		}
	}
}

string *parry_msg = ({
	"$nһ�С��������ء���˫�ֽ�������$N��$w��\n",
	"$nʹ��һ�С����Ҷ����˫��˲�乥�����У�������$N�Ĺ��ơ�\n",
});

string *unarmed_parry_msg = ({
	"$nʹ��һ�С�ɽɽ��项��˫��˲�乥�����У�������$N�Ĺ��ơ�\n",
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
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 0;
}
