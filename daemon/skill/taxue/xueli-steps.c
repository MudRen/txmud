// xueli-steps.c ѩ��̽��

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
HIW"$n����һ�����ģ���������б���벽��ǡ������ѩ��̽���С��������塹�Ĳ��ӣ����˿�����\n"NOR,
HIR"$nʹ���������ѩ������бб���˼������ƺ������·���ȴ�ڼ䲻�ݻ��Ŀ�϶�ж����$N�Ĺ��ơ�\n"NOR,
HIM"$nһʽ��Ʈ�����񡹣�����б�����������ȼá���������δ�á������ü��������۵�$N�����\n"NOR,
HIC"$nһʽ��ѩ��̽·�����ƺ��Թ��Ե�̤����������ᣬÿһ����̤�ڱ������벻�������ڡ�\n"NOR,
MAG"$N����ʽ�������԰�$nΧס����֪���ģ�$nһʽ�����Ʊ��¡���������Ȱ�Ŀ����Ȧ��\n"NOR,
});


int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move" ;
}

int valid_learn(object me)
{
    if ((int)me->query_skill("literate", 1) < 30)
		return notify_fail("���֪ʶ�������޷����ѩ��̽����\n");

    if( me->query_skill_mapped("force") != "taxue-force" )
		return notify_fail("Ҫ��ѧϰ��ѩ��̽����������������̤ѩ�񹦡���\n");

	   return 1;
}


string query_dodge_msg(object me)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int effective_level() { return 12;}

int practice_skill(object me)

{
	if( (int)me->query("kee") < 50
	|| (int)me->query("sen") < 50 )
		return notify_fail("������״��̫���ˣ�������ϰ��ѩ��̽������\n");
	me->receive_damage("kee", 20);
	me->receive_damage("sen", 20);
	me->receive_damage("gin", 10);
	me->improve_skill("force", (int)me->query("int")/2);
	return 1;
}