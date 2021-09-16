// huashan tiyun-steps.c

#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
	"$n�������������ϰ��𣬱ܿ�����һ�С�\n",
	"$n��Ʈ�������ƶ�������������һ�ԡ�\n",
	"����$n��Ӱһ�࣬�ڼ䲻�ݷ�֮�ʴ��ݵرܿ�����һ�С�\n",
	"$n���ζ�Ȼ�θߣ�ʹ$N�Ĺ��ƾ�����ա�\n",
	"$n����һ�㣬��Ӱ���󻬿����ߣ��ܽ���ȥ��\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( me->query_skill_mapped("force") != "zixia-force" )
		return notify_fail("��ϰ�����Ʋ�����������ϡ���ϼ�񹦡���\n");

        return 1;
}

int effective_level() { return 12;}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 50
	|| (int)me->query("sen") < 50 )
		return notify_fail("������״��̫���ˣ�������ϰ�����Ʋ�������\n");
	me->receive_damage("kee", 20);
	me->receive_damage("sen", 20);
	return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/tiyun-steps/" + action;
}
