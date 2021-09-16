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
		return notify_fail("��Ҫ��ʲô��\n");

	if(!mapp(q = me->query("quest/rain_quest"))
	|| (q["quest"] != "ҩ����") )
		return notify_fail("��Щ���������������ɡ�\n");

	if(q["finish"])
		return notify_fail("��ȥ������ɡ�\n");

	if(!ob = present("medicine hoe",me))
		return notify_fail("��û�д�ҩ����ô���أ�\n");

	if( (who && (who != me->query("id"))) || !who )
	{
		now = time();

		if( who && (now - time < 180)
		&& ((bhoe < 5) || (bpour < 3)) )
			return notify_fail("�Ѿ������ڷ������ˣ���ȥ��ĵط������ɡ�\n");

		if(!ctl = query_ctl_ob())
			return notify_fail("�޷��ҵ�����Ա���������Ա���档\n");

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
			return notify_fail("�����Ѿ�����ˣ������ȥ�����ˡ�\n");
		else
			return notify_fail("�����Ѿ�ȫ�����ˣ�����Ӧ�ý�ˮ�ˡ�\n");
	}

	if(block)
		return notify_fail("�����������û���ã��ȵ�һ����ɡ�\n");

	block = 1;
	call_out("stop_hoe",8+random(8),me);
	message_vision(sprintf("$N����%s�ڵ����Ϸ���������\n",ob->name()),me);
	return 1;
}

protected void stop_hoe(object me)
{
	block = 0;
	if( (++bhoe >= 5) && me && (environment(me) == this_object()))
		tell_room(this_object(),"�����Ѿ�ȫ�����ˣ�����Ӧ�ý�ˮ�ˡ�\n");
	else
		tell_room(this_object(), "�����������������������һЩ��\n");
}

int do_pour(string arg)
{
	object me = this_player(),ob, ctl;
	mapping q;

	if(arg != "here")
		return notify_fail("��Ҫ��ʲô��\n");

	if(!mapp(q = me->query("quest/rain_quest")) || (q["quest"] != "ҩ����") )
		return notify_fail("��Щ���������������ɡ�\n");

	if(q["finish"])
		return notify_fail("��ȥ������ɡ�\n");

	if(who)
	{
		if(who != me->query("id"))
		{
			int now = time();

			if( (now - time < 180) && ((bhoe < 5) || (bpour < 3)))
				return notify_fail("�Ѿ������ڷ������ˣ���ȥ��ĵط������ɡ�\n");

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
		return notify_fail("���ػ�û����ȫ���ã��ȷ������ٽ�ˮ�ɡ�\n");

	if(!ob = present("water bucket",me))
		return notify_fail("��û�д�ˮͰ��ô���أ�\n");

	if(!ob->is_full())
		return notify_fail("���ˮͰ�ǿյġ�\n");

	message_vision("$N����ˮͰ��������Խ���һ�顣\n",me);
	ob->set_full(0);

	if( ++bpour >= 3 )
	{
		if(ctl = query_ctl_ob())
			ctl->refresh_worker(this_object());
		who = 0;
		bhoe = 0;
		bpour = 0;
		q["finish"] = 1;
		write("�����Ѿ�����ˣ������ȥ�����ˡ�\n");
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
