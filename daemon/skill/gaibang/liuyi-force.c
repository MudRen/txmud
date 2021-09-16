// gaibang liyi-force.c
// by pian

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( me->query_skill("gaibang-force",1) < 40 )
		return notify_fail("��û��ؤ���ķ��ĵ��ӣ�������᡺�����񹦡���Ҫּ��\n");
	return 1;
	
	if( me->query_skill("force",1) < 80 )
		return notify_fail("�����ڹ��ȼ�̫���ˣ��޷���᡺�����񹦡���Ҫּ��\n");
	return 1;
}

int effective_level() { return 18;}

int practice_skill(object me)
{
	if(me->query_skill("liuyi-force",1) < 80)
	        return notify_fail("��ġ������񹦡���Ϊ���������޷���ϰ���������ȡ�\n");
	if( (int)me->query("kee") < 20 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if(me->query("force") < 10)
		return notify_fail("���������������Ϣһ�������ɡ�\n");
	me->add("force", -10);
	me->receive_damage("kee", 10,"tire");
	write("������ȫ�����š������񹦡��й�һ�顣\n");
	return 1;
}

string exert_function_file(string func)
{
	return CLASS_D("gaibang") + "/liuyi-force/" + func;
}
