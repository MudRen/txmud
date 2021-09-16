// sleep.c
// Modified by Find.

void wakeup(object);

int main(object me, string arg)
{
	int rnd;
	mapping fam;
	object where = environment(me);
	mixed rtn;

	seteuid(getuid());

	if( where->query("no_sleep_room")
	|| where->query("GATE_ROOM") )
		return notify_fail("这里不是你能睡的地方！\n");

	if( !(fam = me->query("family")) || (fam["family_name"] != "丐帮") )
	{
		rtn = where->query("sleep_room", 1);

		if( (functionp(rtn) && !evaluate(rtn, me)) || !rtn )
			return notify_fail("这里不是你能睡的地方！\n");
	}

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if( me->is_fighting() )
		return notify_fail("你正在和别人打架呢！\n");
        
	if(where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("店小二从门外对$N大叫: 把这里当避难所啊! 先到一楼付钱后再来睡!\n",me);
		return 1;
	}

	if( (me->query_temp("newlogin")
	|| ((time() - me->query_temp("sleeped")) <= 30))
	&& !where->query("hotel"))
	{
		me->start_busy(1);
		return notify_fail("你躺下闭上眼，可怎么也睡不着，又站了起来。 \n");
	}

        if( me->query_temp("on_rided") )  // 判断是否骑着坐骑
                return notify_fail("你正骑在欢蹦乱跳的坐骑上怎么休息呀。\n");

	if(where->query("sleep_room"))
	{
		tell_object(me,"你往床上一躺，开始睡觉。\n");
		tell_object(me,"不一会儿，你就进入了梦乡。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n",me);
	}
	else
	{
		tell_object(me,"你往地下角落一躺，开始睡觉。\n");
		tell_object(me,"不一会儿，你就进入了梦乡。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N往地下角落屈身一躺，不一会便鼾声大作，做起梦来。\n",me);
	}

	if(!where->query(SAFE_ENV)) /* by Find. 否则有严重的 bug. */
	{
//		where->set(SAFE_ENV, 1);
		where->set_temp("changed",1);
	}
	where->add_temp("sleeping_person", 1);

	me->set("no_get", 1);
	me->set("no_get_from", 1);
	me->delete_temp("rent_paid");
	me->disable_player("<睡梦中>");

	rnd = random((60 - me->query_con()) / 3);
	if( rnd < 1 ) rnd = 0;
	call_out("wakeup", rnd + 10, me);

	return 1;
}

private void wakeup(object me)
{
	object where;

	if( !me || !(where = environment(me)) )
		return;

	/* 饿、渴，无法通过睡觉恢复体力。*/
	if((me->query("food") && me->query("water")) || !userp(me))
	{
		me->set("gin",me->query("eff_gin"));
		me->set("sen",me->query("eff_sen"));
		me->set("kee",me->query("eff_kee"));
		me->add("force", me->query("max_force")/2 - me->query("force")/2 );
	}

	me->enable_player();
	me->set_temp("block_msg/all", 0);

	if(!me->query("food"))
	{
		tell_object(me,"你肚子饿的叽哩咕噜乱叫，没办法又爬了起来。\n");
		tell_room(where,me->name()+"揉了揉眼睛爬了起来。\n",({me}));
		return;
	}

	if(!me->query("water"))
	{
		tell_object(me,"你渴的口干舌燥，没办法又爬了起来。\n");
		tell_room(where,me->name()+"揉了揉眼睛爬了起来。\n",({me}));
		return;
	}

	if(!where->query("hotel"))
		me->set_temp("sleeped",time());

	tell_room(where,me->name()+"一觉醒来，精力充沛地活动了一下筋骨。\n",({me}));

	tell_object(me,"你一觉醒来，只觉精力充沛。该活动一下了。\n");


	if(where->query_temp("changed"))
	{
//		where->delete(SAFE_ENV);
		where->delete_temp("changed");
	}

	where->add_temp("sleeping_person", -1);
	me->delete("no_get");
	me->delete("no_get_from");
	if(!userp(me))
		me->have_wake_up();
}
