// zhuzao.c

inherit SKILL;

int valid_learn(object me)
{
        if( (int)me->query_skill("zhuzao") >=  30)
                return notify_fail("���켼�ɵ�������̶�ֻ�ܴ�ʵ������ߡ�\n");

        return 1;
}

int practice_skill(object me)
{
        if( (int)me->query_skill("zhuzao") >=  10)
                return notify_fail("���켼�ɵ�������̶�ֻ�ܴ�ʵ������ߡ�\n");
        return 1;
}

int effective_level() { return 10;}

int learn_bonus()
{
	return -200;
}
int practice_bonus()
{
	return -110;
}
int black_white_ness()
{
	return 0;
}
