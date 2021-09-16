// suiyu-force.c
// 随雨无风心法

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int effective_level() { return 12;}

int valid_learn(object me)
{
	if( me->query("bellicosity") > 10 )
                return notify_fail("你的杀气太高，无法领悟更高深的『随雨无风心法』。\n");
        return 1;
}

int practice_skill(object me)
{
	if(me->query_skill("suiyu-force",1) < 250)
	        return notify_fail("你的『随雨无风心法』修为不够，还无法练习增加熟练度。\n");
	if( (int)me->query("kee") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if(me->query("force") < 10)
		return notify_fail("你的真气不够，休息一下再练吧。\n");
	me->add("force", -5);
	me->receive_damage("kee", 25,"tire");
	write("你气走全身，照着『随雨无风心法』行功一遍。\n");
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

