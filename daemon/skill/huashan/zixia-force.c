// huashan zixia-force.c

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( me->query_skill("literate",1) < 30 )
		return notify_fail("�������ɣ�Ҫ���������᡺��ϼ�񹦡���Ҫּ��\n");
	return 1;
}

int effective_level() { return 12;}

int practice_skill(object me)
{
	if(me->query_skill("zixia-force",1) < 280)
	        return notify_fail("��ġ���ϼ�񹦡���Ϊ���������޷���ϰ���������ȡ�\n");
	if( (int)me->query("kee") < 40 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if(me->query("force") < 20)
		return notify_fail("���������������Ϣһ�������ɡ�\n");
	me->add("force", -10);
	me->receive_damage("kee", 35,"tire");
	write("������ȫ�����š���ϼ�񹦡��й�һ�顣\n");
	return 1;
}

string exert_function_file(string func)
{
	return CLASS_D("huashan") + "/zixia-force/" + func;
}
