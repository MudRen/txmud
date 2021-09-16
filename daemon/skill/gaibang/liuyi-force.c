// gaibang liyi-force.c
// by pian

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( me->query_skill("gaibang-force",1) < 40 )
		return notify_fail("你没有丐帮心法的底子，很难领会『六意神功』的要旨。\n");
	return 1;
	
	if( me->query_skill("force",1) < 80 )
		return notify_fail("基础内功等级太低了，无法领会『六意神功』的要旨。\n");
	return 1;
}

int effective_level() { return 18;}

int practice_skill(object me)
{
	if(me->query_skill("liuyi-force",1) < 80)
	        return notify_fail("你的『六意神功』修为不够，还无法练习增加熟练度。\n");
	if( (int)me->query("kee") < 20 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if(me->query("force") < 10)
		return notify_fail("你的真气不够，休息一下再练吧。\n");
	me->add("force", -10);
	me->receive_damage("kee", 10,"tire");
	write("你气走全身，照着『六意神功』行功一遍。\n");
	return 1;
}

string exert_function_file(string func)
{
	return CLASS_D("gaibang") + "/liuyi-force/" + func;
}
