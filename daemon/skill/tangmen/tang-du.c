// tang-du.c
// ���Ŷ���

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage)
{
	return usage=="medicine";
}

int valid_learn(object me)
{
	if(me->query_skill("medicine", 1) < 200)
		return notify_fail("���ҽҩ֪ʶ����ǳ�����޷��������Ŷ�������\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�����Ŷ�����ֻ��ͨ��ѧϰ��ʵ������ߡ�\n");
}

void skill_improved(object me)
{

}

int learn_bonus()
{
	return -80;
}
