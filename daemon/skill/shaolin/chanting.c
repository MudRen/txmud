// chanting.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
	return notify_fail("诵经只有在诵读经文的时候才能有所领悟。\n");
}

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

