// unride.c
// design by 发现号 (find)

inherit F_CLEAN_UP;

int main(object me)
{
	object rided;
	string str;

	if( !me->query_temp("on_rided"))
		return notify_fail("你没有骑在任何坐骑上。\n");
	me->start_busy(1);

	rided = me->query_temp("on_rided");
	me->delete_temp("on_rided");
	if(me->query_temp("add/dodge"))
	{
		me->add_temp("apply/dodge",-(int)me->query_temp("add/dodge"));
		me->delete_temp("add/dodge");
	}

	rided->delete_temp("have_been_rided");
	rided->set_leader();

	if( !stringp(str = rided->query("unride_msg")) )
	str = "$N从$n上跳了下来。\n";
	else if(strsrch(str,"\n") == -1)
		str += "\n";
	message_vision(str, me, rided);

	me->delete_temp("ride_time");
	me->delete_temp("ride_pass");
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式：unride
 
这个指令让你可以从目前所骑的坐骑上跳下来。
 
HELP
    );
    return 1;
}