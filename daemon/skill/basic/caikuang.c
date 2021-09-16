// caikuang.c

inherit SKILL;

int valid_learn(object me)
{
        if( (int)me->query_skill("caikuang") >=  30)
                return notify_fail("采矿技法到了这个程度只能从实践中提高。\n");

        return 1;
}

int practice_skill(object me)
{
        if( (int)me->query_skill("caikuang") >=  10)
                return notify_fail("采矿技法到了这个程度只能从实践中提高。\n");
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

