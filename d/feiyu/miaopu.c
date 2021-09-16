// Room: /d/feiyu/miaopu1.c

inherit ROOM;

protected string who;
protected int time,bhoe,bpour,block;
protected object control;

protected object query_ctl_ob()
{
	if( !control
	&& !objectp(control = find_object(__DIR__"mp_control"))
	&& !objectp(control = load_object(__DIR__"mp_control")) )
		return 0;

	return control;
}

void init()
{
	add_action("do_hoe","hoe");
	add_action("do_pour","pour");
}

int do_hoe(string arg)
{
	int now;
	object me = this_player(),ob, ctl;
	mapping q;

	if(arg != "here")
		return notify_fail("你要干什么？\n");

	if(!mapp(q = me->query("quest/rain_quest"))
	|| (q["quest"] != "药苗圃") )
		return notify_fail("这些事情让其他人做吧。\n");

	if(q["finish"])
		return notify_fail("快去交任务吧。\n");

	if(!ob = present("medicine hoe",me))
		return notify_fail("你没有带药锄怎么锄地？\n");

	if( (who && (who != me->query("id"))) || !who )
	{
		now = time();

		if( who && (now - time < 180)
		&& ((bhoe < 5) || (bpour < 3)) )
			return notify_fail("已经有人在翻这块地了，你去别的地方看看吧。\n");

		if(!ctl = query_ctl_ob())
			return notify_fail("无法找到控制员，请向管理员报告。\n");

		who = 0;

		if(!ctl->valid_begin(this_object(), me->query("id")))
			return 0;

		who = me->query("id");
		time = now;
		bhoe = 0;
		bpour = 0;
	}

	if(bhoe >= 5)
	{
		if(bpour >= 3)
			return notify_fail("这块地已经搞好了，你可以去交差了。\n");
		else
			return notify_fail("这块地已经全翻过了，现在应该浇水了。\n");
	}

	if(block)
		return notify_fail("这条垅的土还没翻好，先等一会儿吧。\n");

	block = 1;
	call_out("stop_hoe",8+random(8),me);
	message_vision(sprintf("$N拿起%s在地垅上翻起土来。\n",ob->name()),me);
	return 1;
}

protected void stop_hoe(object me)
{
	block = 0;
	if( (++bhoe >= 5) && me && (environment(me) == this_object()))
		tell_room(this_object(),"这块地已经全翻过了，现在应该浇水了。\n");
	else
		tell_room(this_object(), "经过翻整，地里的土疏松了一些。\n");
}

int do_pour(string arg)
{
	object me = this_player(),ob, ctl;
	mapping q;

	if(arg != "here")
		return notify_fail("你要做什么？\n");

	if(!mapp(q = me->query("quest/rain_quest")) || (q["quest"] != "药苗圃") )
		return notify_fail("这些事情让其他人做吧。\n");

	if(q["finish"])
		return notify_fail("快去交任务吧。\n");

	if(who)
	{
		if(who != me->query("id"))
		{
			int now = time();

			if( (now - time < 180) && ((bhoe < 5) || (bpour < 3)))
				return notify_fail("已经有人在翻这块地了，你去别的地方看看吧。\n");

			if(!ctl = query_ctl_ob())
				return 0;

			who = 0;

			if(!ctl->valid_begin(this_object(), me->query("id")))
				return 0;
			who = me->query("id");
			time = now;
			bhoe = 0;
			bpour = 0;
		}
	}
	else
	{
		if(!ctl = query_ctl_ob())
			return 0;

		who = 0;

		if(!ctl->valid_begin(this_object(), me->query("id")))
			return 0;

		who = me->query("id");
		time = time();
		bhoe = 0;
		bpour = 0;
	}

	if(bhoe < 5)
		return notify_fail("这块地还没有完全翻好，等翻好了再浇水吧。\n");

	if(!ob = present("water bucket",me))
		return notify_fail("你没有带水桶怎么浇地？\n");

	if(!ob->is_full())
		return notify_fail("你的水桶是空的。\n");

	message_vision("$N提起水桶把这块苗圃浇了一遍。\n",me);
	ob->set_full(0);

	if( ++bpour >= 3 )
	{
		if(ctl = query_ctl_ob())
			ctl->refresh_worker(this_object());
		who = 0;
		bhoe = 0;
		bpour = 0;
		q["finish"] = 1;
		write("这块地已经搞好了，你可以去交差了。\n");
	}

	return 1;
}

int valid_leave(object me,string dir)
{
	if(who && (me->query("id") == who))
		if(find_call_out("stop_hoe") != -1)
		{
			block = 0;
			remove_call_out("stop_hoe");
		}

	return ::valid_leave(me,dir);
}
