// taxue-force.c
// by dicky.

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( me->query_skill("literate",1) < 30 )
		return notify_fail("��ȥ�����Ļ���ѧʶ�ɣ���Ȼ�������᡺̤ѩ�񹦡���Ҫּ��\n");
	return 1;
}

int effective_level() { return 12;}

int practice_skill(object me)
{
	if(me->query_skill("taxue-force",1) < 250)
	        return notify_fail("��ġ�̤ѩ�񹦡���Ϊ���������޷���ϰ���������ȡ�\n");
	if( (int)me->query("kee") < 40 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if(me->query("force") < 20)
		return notify_fail("���������������Ϣһ�������ɡ�\n");
	me->add("force", -5);
	me->receive_damage("kee", 25,"tire");
	write("�������뵤����š�̤ѩ�񹦡���������ת�����������չ���˫��̧��վ��������\n");
	return 1;
}

string exert_function_file(string func)
{
	return CLASS_D("taxue") + "/taxue-force/" + func;
}


/* �ڹ��Ƿ��д�͸���׵�����������ﴫ������ɽ��ţ֮��
int query_through_armor(object me,int factor)
{
	int level,ret;

	if(!me || factor < 10)
		return 0;

	level = me->query_skill("yiqi-force",1);
	if(level < 50)
		return 0;

	ret = (level + factor)/5;
	return ret;
}
*/