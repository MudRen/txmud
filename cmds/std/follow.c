// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("指令格式：follow <某人>|none。\n");

	if( arg=="none")
		if( me->query_leader() )
		{
			me->set_leader(0);
			write("Ok.\n");
			if(me->is_fighting())
				me->start_busy(1);
			return 1;
		} else {
			write("你现在并没有跟随任何人。\n");
			return 1;
		}

	if( !objectp(ob = present(arg, environment(me)))
	|| !ob->is_character() )
		return notify_fail("你要跟随谁？\n");

	if( ob==me )
		return notify_fail("跟随自己？\n");

	if( me->in_team() )
		return notify_fail("你现在是队伍的成员，不能再跟随别人了。\n");

	if(ob->in_team())
		return notify_fail(ob->name()+"是其他队伍的成员，你没法跟随。\n");

	if( me->in_array() )
		return notify_fail(sprintf("你目前是『%s』的成员，无法跟随其他人。\n",
			ob->query_array_name() ));

	if( ob->in_array() )
		return notify_fail(sprintf("%s是『%s』的成员，你无法跟随。\n",
			ob->name(),ob->query_array_name() ));

	me->set_leader(ob);
	message_vision("$N决定开始跟随$n一起行动。\n", me, ob);
	if(me->is_fighting())
		me->start_busy(1);
	return 1;
}

int help (object me)
{
        write(@HELP
指令格式 : follow [<生物>|none]
 
这个指令让你能跟随某人或生物。
如果输入 follow none 则停止跟随。
 
HELP
);
        return 1;
}
