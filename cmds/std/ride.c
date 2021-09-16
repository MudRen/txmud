// ride.c
// by Find

#include <ansi.h>
inherit F_CLEAN_UP;

int do_ride(object me, object ob);

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("你要骑什么？\n");
	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("你要骑什么？\n");
	if( me->query_temp("on_rided") )
		return notify_fail("你已经骑在"+(me->query_temp("on_rided"))->name()+"上了。\n");
	if( !ob->query("ride") )
		return notify_fail("那不是坐骑，你不能骑。\n");
	if(me->is_fighting())
		return notify_fail("你正在战斗，没有时间上坐骑。\n");
	if(ob->is_fighting())
		return notify_fail(ob->name()+"正在战斗中，你现在没法骑它。\n");
	if( !living(ob) )
		return notify_fail(ob->name()+"已经晕倒在地，现在不能骑它。\n");

	return do_ride(me, ob);
}

int do_ride(object me, object ob)
{
	string str;
	int ride_level,skill,ride_dodge;

	if(ob->query_temp("have_been_rided"))
		return notify_fail(ob->name()+"正驮着"+
		(string)((ob->query_temp("have_been_rided"))->name())+"。\n");

	if(ob->is_wild() && (ob->query_master() != me))
		return notify_fail(sprintf("%s扭了扭身子，把你甩了下来。\n",ob->name()));

#ifdef WIZARD_FLAG
	if(ob->query_wiz_flag() && !wizardp(me))
		return notify_fail("那是巫师们的天马，你不能骑。\n");
#endif

	ride_level = ob->query("ride_level");	// 坐骑的等级
	skill = me->query_skill("riding",1);	// 骑术等级

	if(ride_level > 10)
		ride_level = 10;
	if(ride_level < 1)
		ride_level = 1;

	me->start_busy(1);

	if(ride_level > 2 && ride_level <= 5 )	// 3 级坐骑
	{
		if(skill < 20)	// 需要20级以上的骑术
		{
			message_vision("$N侧身爬到了$n的背上。\n$n一甩身子又把$N扔了下来。\n",me,ob);
			return notify_fail("看样子你的骑术还不够精纯。\n");
		}
	}

	if(ride_level > 5 && ride_level <= 8 )	// 2 级坐骑
	{
		if(skill < 100)	// 需要100级以上的骑术
		{
			message_vision("$N侧身跃上$n。\n$n一声长鸣，一甩身子又把$N扔了下来。\n",me,ob);
			return notify_fail("看样子你的骑术还不够精纯。\n");
		}
	}

	if(ride_level > 8 )	// 1 级坐骑
	{
		if(skill < 150)	// 需要150级以上的骑术
		{
			message_vision("$N侧身跃上$n。\n$n一甩身子又把$N扔了下来。\n",me,ob);
			return notify_fail("看样子你的骑术还不够精纯。\n");
		}
	}

	me->set_temp("on_rided", ob);

	ob->set_leader(me);
	ob->set_temp("have_been_rided",me);

	if( !stringp(str = ob->query("ride_msg")) )
		str = "$N飞身一跃骑上了$n。\n";
	else if(strsrch(str,"\n") == -1)
		str += "\n";
	message_vision(str, me, ob);

	// 此处为骑上坐骑后防御力的修正值的计算公式.
	ride_dodge = ride_level*skill/40;

	if(ride_dodge < 1 )
		ride_dodge = 1;

	me->add_temp("apply/dodge", ride_dodge);
	me->set_temp("add/dodge",ride_dodge);
	me->set_temp("ride_time",time());
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式：ride <要骑上的坐骑名称>
 
这个指令可以让你骑在某头坐骑上, 但它必需和你在同一环境中。
 
HELP
    );
    return 1;
}