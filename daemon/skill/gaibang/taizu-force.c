// gaibang taizu-force.c
// by pian

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( me->query_skill("literate",1) < 5 )
		return notify_fail("多读读书吧，要不你很难领会『太祖心法』的要旨。\n");
	return 1;
}

int effective_level() { return 10;}

int practice_skill(object me)
{
	if(me->query_skill("taizu-force",1) < 250)
	        return notify_fail("你的『太祖心法』修为不够，还无法练习增加熟练度。\n");
	if( (int)me->query("kee") < 20 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if(me->query("force") < 10)
		return notify_fail("你的真气不够，休息一下再练吧。\n");
	me->add("force", -10);
	me->receive_damage("kee", 10,"tire");
	write("你气走全身，照着『太祖心法』行功一遍。\n");
	return 1;
}

string exert_function_file(string func)
{
	return CLASS_D("gaibang") + "/taizu-force/" + func;
}
