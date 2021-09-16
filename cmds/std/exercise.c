// exercise.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int kee_cost, rn;

        if( me->query_temp("exercise"))
		return notify_fail("你现在已经处于运功状态，不能再运功了。\n");

	if( me->is_fighting() )
                return notify_fail("战斗中不能练内功，会走火入魔。\n");

	if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

        if( !arg || !sscanf(arg, "%d", kee_cost) )
                return notify_fail("你要花多少气练功？\n");

	if( kee_cost < 10 )
		return notify_fail("你最少要花 10 点「气」才能练功。\n");

        if( (int)me->query("kee") < kee_cost )
                return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
                return notify_fail("你现在精神状况太差了，无法凝神专一！\n");

        if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
                return notify_fail("你现在精力不够，无法控制内息的流动！\n");

        write("你坐下来闭上眼睛运气用功，一股内息开始在体内流动。\n");

	rn=random(3);
	me->start_busy(5);
	call_out("do_exercise",3+rn,me,kee_cost);
	return 1;
}

private void do_exercise(object me,int kee_cost)
{
	int force_gain;
        me->receive_damage("kee", kee_cost);
        message_vision("$N行功完毕，缓缓的睁开眼睛，站了起来。\n", me);

	if(!objectp(me))
		return;

        force_gain = kee_cost * ((int)me->query_skill("force",1)+ 25 ) / 400;

	seteuid(getuid());

	if( force_gain < 1 )
		tell_object(me,"但是你只觉得全身发麻，大概用来调吸的内力太少了。\n");
	else
	{
		me->add("force", force_gain );
		if( (int)me->query("force") > (int)me->query("max_force") * 2)
		{
			if( (int)me->query("max_force") >= ((int)me->query_skill("force", 1) +
			(int)(me->query_skill("force")/3) ) * 10 )
			{
				me->set("force", me->query("max_force")*2);
				tell_object(me,"你打坐调吸后功力没有任何提升的迹象，似乎内力修为已经遇到了瓶颈。\n");
			}
			else
			{
				write(HIC"你的内力增强了！\n"NOR);
				me->add("max_force", 1);
				me->set("force", me->query("max_force"));
			}
		}
	}

	me->stop_busy();
}

int help(object me)
{
        write(@HELP
指令格式 : exercise [<耗费「气」的量，预设值 30>]
           exercise 可简写为 dazuo

运气打坐练功，控制体内的气在各经脉间流动，藉以训练人
体肌肉骨骼的耐力、爆发力，并且用内力的形式将能量储备
下来。

请参考 help stats
HELP
        );
        return 1;
}
