// huashan tiyun-steps.c

#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
	"$n身形向轻轻向上拔起，避开了这一招。\n",
	"$n身法飘忽，逆势而动，身子闪在一旁。\n",
	"但是$n身影一侧，在间不容发之际从容地避开了这一招。\n",
	"$n身形陡然拔高，使$N的攻势尽数落空。\n",
	"$n右足一点，身影向左滑开数尺，避将开去。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( me->query_skill_mapped("force") != "zixia-force" )
		return notify_fail("练习『凌云步法』必须配合『紫霞神功』。\n");

        return 1;
}

int effective_level() { return 12;}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 50
	|| (int)me->query("sen") < 50 )
		return notify_fail("你身体状况太差了，不能练习『凌云步法』。\n");
	me->receive_damage("kee", 20);
	me->receive_damage("sen", 20);
	return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/tiyun-steps/" + action;
}
