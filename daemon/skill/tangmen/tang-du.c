// tang-du.c
// 唐门毒功

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
		return notify_fail("你的医药知识过于浅薄，无法领悟『唐门毒功』。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("『唐门毒功』只能通过学习和实践来提高。\n");
}

void skill_improved(object me)
{

}

int learn_bonus()
{
	return -80;
}
