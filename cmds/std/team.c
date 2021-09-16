// team.c
// by Find

#define MAX_TEAM_MEMBER	4

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object);

int main(object me, string arg)
{
	object *t, leader;
	if( !arg )
	{
		if( !me->in_team() )
			return notify_fail("你现在并没有参加任何队伍。\n");

		if((leader = me->query_team_leader()) == me)
			printf("你带领的队伍中的成员有：\n  %s\n\n",
				implode(me->query_team_member()->name(1), "\n  "));
		else
			printf("你正在%s带领的队伍中，成员有：\n  %s\n\n",
				leader->name(1), implode(me->query_team_member()->name(1), "\n  "));
		return 1;
	}

	// 如果是首领，就是解散队伍
	// 是成员，脱离队伍
	if( arg=="san" )
	{
		if( !me->in_team() )
			return notify_fail("你现在并没有参加任何队伍。\n");

		if( me->is_team_leader() )
		{
			message("team", me->name(1) + "将队伍解散了。\n", me->query_team_member(), me);
			write("你将队伍解散了。\n");
		}

		else
		{
			message("team", me->name(1) + "决定离开队伍。\n", me->query_team_member(), me);
			write("你离开了队伍。\n");
		}

		me->dismiss_team();
		return 1;
	}

	// 发起
	if( sscanf(arg, "yq %s", arg)==1 )
	{
		object ob;
		int m_exp, o_exp;

		if(me->in_team())
		{
			if(!me->is_team_leader())
				return notify_fail("只有队伍首领才能邀请别人加入。\n");
			if(sizeof(me->query_team_member()) >= MAX_TEAM_MEMBER)
				return notify_fail("你的队伍人数已经达到了最大人数。\n");
		}

		if( !(ob = present(arg, environment(me)))
		|| !living(ob)
		|| !userp(ob)
		|| (ob==me) )
			return notify_fail("你想邀请谁加入你的队伍？\n");

		if( (wizardp(me) && !wizardp(ob))
		|| (!wizardp(me) && wizardp(ob)) )
			return notify_fail("巫师和玩家不能组队。\n");

		if(ob->in_array())
			return notify_fail("对方正在其它的阵法中，无法参加你的队伍。\n");

		m_exp = me->query("combat_exp");

		if( ((o_exp = ob->query("combat_exp")) < m_exp/10*8)
		|| (o_exp > m_exp*1.2) )
			return notify_fail(ob->name()+"的经验和你相差过远，无法组成队伍。\n");

		if(me->is_team_member(ob))
			return notify_fail(ob->name()+"已经是你队伍的成员了。\n");

		if(ob->in_team())
			return notify_fail(ob->name()+"已经是其它队伍的成员了。\n");

		if(ob->in_array())
			return notify_fail(sprintf("%s是%s的成员，不能加入你的队伍。\n",
				ob->name(), ob->query_array_name()));

		message_vision("$N邀请$n加入$P的队伍。\n", me, ob);
		tell_object(ob, sprintf(BWHT HIG"如果你愿意可以用 team in %s 命令加入。\n"NOR, me->query("id")));
		ob->set_temp("pending/team", me);
		return 1;
	}

	// 加入
	if( sscanf(arg, "in %s", arg)==1 )
	{
		object ob = me->query_temp("pending/team");
		int m_exp, o_exp;

		if(!ob || !arg)
			return notify_fail("并没有人向你发出入队的邀请。\n");

		if(geteuid(ob) != arg)
			return notify_fail(arg+"这个人并没有向你发出入队的邀请。\n");

		if(sizeof(ob->query_team_member()) >= MAX_TEAM_MEMBER)
				return notify_fail("对方队伍人数已经达到了最大人数，你不能再加入了。\n");

		if(me->in_array())
			return notify_fail("你正在阵法中，无法加入其它的队伍。\n");

		m_exp = ob->query("combat_exp");
		if( ((o_exp = me->query("combat_exp")) < m_exp/10*8)
		|| (o_exp > m_exp*1.2) )
			return notify_fail(sprintf("你的经验和%s相差过远，无法组成队伍。\n", ob->name()));

		if(me->in_team())
			return notify_fail(sprintf("你已经是%s队伍的成员了。\n",
				(me->query_team_leader()==ob)?"":"其它"));

		if(me->in_array())
			return notify_fail(sprintf("你是%s的成员，不能加入其它的队伍。\n",
				me->query_array_name()));

		ob->add_team_member(me);
		printf("你应邀加入了%s带领的队伍。\n", ob->name());
		me->delete_temp("pending/team");
		return 1;
	}

	if( sscanf(arg, "talk %s", arg)==1 )
	{
		if( !me->in_team() || !sizeof(t=me->query_team_member()) )
			//return notify_fail("你现在并没有在队伍中。\n");
			return 0;

		message("team", sprintf(HIW "【队伍】%s：%s\n" NOR,me->name(1),arg), t);
		return 1;
	}

	return help(me);
}

int help(object me)
{
	write(@HELP
队伍指令使用方法:

team		显示你所在的队伍的成员名单。

team san	队伍的首领解散所组建的队伍。
		此命令可简写为：ts

team yq <ID>	首领邀请某人加入你的队伍。
		被邀请人的经验和你相差不能超过 20% 。
		此命令可简写为：tyq

team in <ID>	接受邀请加入队伍。
		此命令可简写为：tin

team talk	队伍成员之间的交谈。
		此命令可简写为：tt

HELP
	);
	return 1;
}
