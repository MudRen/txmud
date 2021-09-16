// dacheng-fofa.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="magic"; }

int valid_learn(object me)
{
	if( (me->query("class") != "shaolin") || !me->query("is_bonze") )
		return notify_fail("���������µĳ���ɮ�����������˷𷨵ľ�Ҫ��\n");

	if( (int)me->query_skill("dacheng-fofa",1) >= (int)me->query_skill("chanting",1) )
		return notify_fail("����ڷ𾭵��ж����в����������������������Ĵ�˷𷨡�\n");
	return 1;
}

string conjure_magic_file(string spell)
{
	return CLASS_D("shaolin") + "/dacheng-fofa/" + spell;
}

int effective_level() { return 10;}

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
