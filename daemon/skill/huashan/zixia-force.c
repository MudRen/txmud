// huashan zixia-force.c

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( me->query_skill("literate",1) < 30 )
		return notify_fail("多读读书吧，要不你很难领会『紫霞神功』的要旨。\n");
	return 1;
}

int effective_level() { return 12;}

int practice_skill(object me)
{
	if(me->query_skill("zixia-force",1) < 280)
	        return notify_fail("你的『紫霞神功』修为不够，还无法练习增加熟练度。\n");
	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if(me->query("force") < 20)
		return notify_fail("你的真气不够，休息一下再练吧。\n");
	me->add("force", -10);
	me->receive_damage("kee", 35,"tire");
	write("你气走全身，照着『紫霞神功』行功一遍。\n");
	return 1;
}

string exert_function_file(string func)
{
	return CLASS_D("huashan") + "/zixia-force/" + func;
}
