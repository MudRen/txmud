// vote command..
// Modified by Marz, 04/18/96
// Modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	object victim;
	string act_name, victim_name;
	string file;
	object file_ob;

	if( wizardp(me) )
		return notify_fail("巫师不允许投票。\n");

	seteuid(getuid());

	if( me->query("age") <= PROTECT_AGE )
		return notify_fail("民主不是儿戏！等你长大成人以后再说吧！\n");

	if((int)me->query("deprived"))
	{
		if(((int)me->query("deprived")-me->query("mud_age"))<= 86400)
		/* 每次剥夺投票权的时间为 mud_age 24小时. */
			return notify_fail("你由于无视民主权力的严肃性被剥夺了投票权。\n");
		else
			me->delete("deprived");
	}

	if (!arg || sscanf(arg, "%s %s", act_name, victim_name) != 2)
		return help(me);
    
	victim = LOGIN_D->find_body(victim_name);
	if(!victim || victim == me || wizardp(victim)) /* 不能为自己投票 */
		return notify_fail("你要投谁的票？\n");

	if( file_size((file = sprintf(__DIR__"vote/%s",act_name)) + ".c") <= 0 )
		return notify_fail("你要投票干什么？\n");

	if( !(file_ob = find_object(file)) )
		file_ob = load_object(file);
	if(!file_ob)
		return notify_fail("你要投票干什么？\n");

	if(victim->query("vote/time")	/* 超过5分钟前一动议失效. */
	&& (time() - victim->query("vote/time")) > 300)
		victim->delete("vote");

	if((int)file_ob->vote(me, victim) <= 0)
	{
		if ((int)me->query("abuse")> 50)
		{
			write( HIG "你因为胡乱投票，投票权被剥夺了！\n" NOR);
			me->set("deprived", me->query("mud_age"));
			me->delete("abuse");
		}
		return 0;
	}

	return 1;
}


int valid_voters(object me)
{
	object *list;
	int d = 0, j;

	list = users();
	j = sizeof(list);

	while( j-- )
	{
		// Skip those users in login limbo.
		if( !environment(list[j]) ) continue;
		if( !me->visible(list[j]) ) continue;
		if( list[j]->query_temp("netdead") ) continue;
		if(((int)list[j]->query("age")<=PROTECT_AGE) || wizardp(list[j])) continue;
		if((int)list[j]->query("vote/deprived")) continue;
		d++;
	}
	return d;
}


int help(object me)
{
write(@HELP
指令格式 : vote <动议> <某人>

此命令提议对某人采取行动，由大家投票决定。可是如果五分
钟内没有人附议，投票会自动取消。当前可以有如下<动议>：

chblk:
	关闭某人交谈频道，需要在线合法投票人总和的
	五分之一不少于五票同意。

unchblk:
	打开某人交谈频道，需要在线合法投票人总和的
	五分之一不少于五票同意。

HELP
    );
    return 1;
}
