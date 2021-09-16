// unfuji.c

// 解除伏击. By Find. (11/28/98)

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object *fuji;
	string who;

	if(!who = me->query_temp("fuji_player"))
		return notify_fail("你并没有在伏击别人。\n");

	me->start_busy(1);
	me->delete_temp("fuji_player");
	me->delete("env/invisibility");
	if((fuji = environment(me)->query("fuji/"+who)) && arrayp(fuji))
	{
		fuji -= ({ me });
		environment(me)->set("fuji/"+who,fuji);
	}

	message_vision("$N从藏身之处走了出来。\n",me);
	return 1;
}

int help(object me)
{
        write(@TEXT
指令格式：unfuji

解除伏击状态，从隐身之处走
出来。

TEXT
        );
        return 1;
}