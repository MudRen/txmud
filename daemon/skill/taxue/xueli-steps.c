// xueli-steps.c 雪里探花

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
HIW"$n足下一个踉跄，乘势向左斜出半步，恰符合了雪里探花中「忽焉纵体」的步子，闪了开来。\n"NOR,
HIR"$n使出「流风回雪」歪歪斜斜退了几步，似乎不成章法，却在间不容缓的空隙中躲过了$N的攻势。\n"NOR,
HIM"$n一式「飘忽若神」，侧身斜进，抢步“既济”，立闪“未济”，闪得几闪，已欺到$N的身后。\n"NOR,
HIC"$n一式「雪中探路」，似乎自管自地踏步，毫不理会，每一步都踏在别人意想不到的所在。\n"NOR,
MAG"$N的招式明明可以把$n围住，不知怎的，$n一式「轻云蔽月」，又如鬼魅般的跨出了圈外\n"NOR,
});


int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move" ;
}

int valid_learn(object me)
{
    if ((int)me->query_skill("literate", 1) < 30)
		return notify_fail("你的知识不够，无法领会雪里探花。\n");

    if( me->query_skill_mapped("force") != "taxue-force" )
		return notify_fail("要想学习『雪里探花』，必须修炼『踏雪神功』。\n");

	   return 1;
}


string query_dodge_msg(object me)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int effective_level() { return 12;}

int practice_skill(object me)

{
	if( (int)me->query("kee") < 50
	|| (int)me->query("sen") < 50 )
		return notify_fail("你身体状况太差了，不能练习『雪里探花』。\n");
	me->receive_damage("kee", 20);
	me->receive_damage("sen", 20);
	me->receive_damage("gin", 10);
	me->improve_skill("force", (int)me->query("int")/2);
	return 1;
}