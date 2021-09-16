// gaibang chansi-shou.c ��˿������
// edit pian

#include <ansi.h>
inherit SKILL;
mapping *action = ({
	
([     "action":           HIG"$N˫���繳�����ǲ�˿�����ֵĵ�һʽ"+WHT"���������ˮ��"+HIG"����$n��$l��"NOR,
              "dodge":             -30,
              "parry":             -70,
              "force":             90,
              "damage_type":       "ץ��"
       ]),
([     "action":            HIG"$N������ת������һ��"+WHT"��ˮ�����Ƶ���"+HIG"Ϯ��$n��$l��"NOR,
              "dodge":             -10,
              "parry":             -60,
              "force":             160,
              "damage_type":       "����"
       ]),
([     "action":            HIG"$N����һ����������磬����һ��"+WHT"��ƽɳ��δû��"+HIG"ץ��$n��$l��"NOR,
              "dodge":             -30,
              "parry":             -40,
              "force":             190,
              "damage_type":       "����"
       ]),

([     "action":            HIG"$N��ָ��׶��һ��"+WHT"����������䬡�"+HIG"����$n��$l��"NOR,
              "dodge":             -20,
              "parry":             -50,
              "force":             120,
              "damage_type":       "����"
       ]),

([     "action":            HIG"$Nһʽ"+WHT"�����ճ���ս��"+HIG"���Ծ���׼$n��$lץ����ȥ��"NOR,
              "dodge":             -70,
              "parry":             -40,
              "force":             140,
              "damage_type":       "����"
       ]),

([     "action":            HIG"$N��Ŀ��磬һ�����ȣ�һ��"+WHT"�����������ߡ�"+HIG"�����ƿ�֮��Ϯ��$n��$l��"NOR,
              "parry":             -90,
              "force":             140,
              "damage_type":       "����"
       ]),

([     "action":            HIG"$N���ֵݸ����У�����һʽ"+WHT"���Ƴ���Ž�"+HIG"����$n��$l��"NOR,
              "parry":             -90,
              "force":             130,
              "damage_type":       "����"
       ]),

([     "action":            HIG"$N˫ĿԲ����ʹ��[��˿������]���һʽ"+WHT"���׹������"+HIG"Ϯ��$n��$l��"NOR,
              "parry":             -90,
              "force":             220,
              "damage_type":       "����"
       ]),

});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail(HIY"\n����Ҫ�������ò������򡺲�˿�����֡���\n"NOR);

	if( (int)me->query("max_force") < 200 )
		return notify_fail(HIY"�������̫�����޷���������˿�����֡���\n"NOR);
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
		return notify_fail("���������������������ϰ����˿�����֡���\n");
	if( (int)me->query("force") < 100 )
		return notify_fail("�������������������ϰ����˿�����֡���\n");

	me->receive_damage("kee", 25, "tire");
	me->add("force", -3);
	return 1;
}

int effective_level() { return 14; }

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
			case 4: return "[��˿������]�ֹ�Ȼ�����鴫��$n��$l���̱�ӡ��һ�ǣ�\n";
		}
	}
}

string *parry_msg = ({
	HIG"$nһ�С��׹��������˫�ֽ�������$N��$w��\n"NOR,
	HIG"$nʹ��һ�С��Ƴ���Ž񡹣�˲�乥�����У�ȴ�ܿ���$N�Ĺ��ơ�\n"NOR,
	HIG"$n�������һ�ӣ�һʽ���������ˮ�����ܿ���$N�Ĺ��ơ�\n"NOR,
});

string *unarmed_parry_msg = ({
	"$nʹ��һ�С����ƴ��ա���˫��˲�乥�����У��ܿ���$N�Ĺ��ơ�\n",
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

string perform_action_file(string action)
{
        return CLASS_D("gaibang") + "/chansi-shou/" + action;
}