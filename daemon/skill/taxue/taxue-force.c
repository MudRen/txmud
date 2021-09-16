// taxue-force.c
// by dicky.

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( me->query_skill("literate",1) < 30 )
		return notify_fail("先去提高你的基本学识吧，不然你很难领会『踏雪神功』的要旨。\n");
	return 1;
}

int effective_level() { return 12;}

int practice_skill(object me)
{
	if(me->query_skill("taxue-force",1) < 250)
	        return notify_fail("你的『踏雪神功』修为不够，还无法练习增加熟练度。\n");
	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if(me->query("force") < 20)
		return notify_fail("你的真气不够，休息一下再练吧。\n");
	me->add("force", -5);
	me->receive_damage("kee", 25,"tire");
	write("你吸气入丹田，照着『踏雪神功』，真气运转渐缓，慢慢收功，双手抬起，站了起来。\n");
	return 1;
}

string exert_function_file(string func)
{
	return CLASS_D("taxue") + "/taxue-force/" + func;
}


/* 内功是否有穿透护甲的能力，如借物传力、隔山打牛之类
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