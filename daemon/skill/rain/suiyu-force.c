// suiyu-force.c
// �����޷��ķ�

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int effective_level() { return 12;}

int valid_learn(object me)
{
	if( me->query("bellicosity") > 10 )
                return notify_fail("���ɱ��̫�ߣ��޷����������ġ������޷��ķ�����\n");
        return 1;
}

int practice_skill(object me)
{
	if(me->query_skill("suiyu-force",1) < 250)
	        return notify_fail("��ġ������޷��ķ�����Ϊ���������޷���ϰ���������ȡ�\n");
	if( (int)me->query("kee") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if(me->query("force") < 10)
		return notify_fail("���������������Ϣһ�������ɡ�\n");
	me->add("force", -5);
	me->receive_damage("kee", 25,"tire");
	write("������ȫ�����š������޷��ķ����й�һ�顣\n");
	return 1;
}

string exert_function_file(string func)
{
	return CLASS_D("rain") + "/suiyu-force/" + func;
}

int learn_bonus()
{
        return -30;
}
int practice_bonus()
{
        return -45;
}
int black_white_ness()
{
        return 40;
}

