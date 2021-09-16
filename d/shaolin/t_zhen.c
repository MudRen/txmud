// t_zhen.c
// by Find.

mapping dirs = (["north":"south","south":"north","east":"west","west":"east"]);

void init()
{
        if(previous_object() && userp(previous_object()) && !wizardp(previous_object())
	&& (previous_object()->query_temp("pass_tongren") == (this_object()->query_stage() -1) ) )
	{
		if(find_call_out("do_begin"))
			remove_call_out("do_begin");
		call_out("do_begin",3,previous_object());
	}
	add_action("do_quit","quit");
}

int do_quit()
{
	write("ʲô��\n");
	return 1;
}

int user_cant_die(object user)
{
	int kee, stage = this_object()->query_stage();
	object *obs;

	if(!objectp(user)
	|| !userp(user)
	|| !environment(user)
	|| environment(user) != this_object())
		return 0;

	user->set("eff_kee",(kee = user->query("max_kee")));
	user->set("kee",kee);

	user->remove_all_killer();
	tell_object(user,sprintf("�㴳��ͭ�����ڵ�%s��ʧ���ˡ�\n",chinese_number(stage)));
	user->move(__DIR__"yongdao2");
	tell_room(__DIR__"yongdao2",sprintf("%s����ײײ�����˹�����\n",user->name()));

	obs = all_inventory(this_object());
	obs -= ({0});

	if(sizeof(obs))
		foreach(object ob in obs)
			destruct(ob);

	return 1;
}

protected void do_begin(object me)
{
	mapping exits;

	if(!me || environment(me) != this_object())
		return;

	if(mapp(exits = this_object()->query("exits")) && sizeof(exits))
	{
		foreach(string dir,string file in exits)
		{
			object room = find_object(file);

			tell_room(this_object(),sprintf("ֻ����һ��֨֨�¸¡����죬%s���ʯ������ˡ�\n\n",
				to_chinese(dir)));
			this_object()->delete(sprintf("exits/%s",dir));

			if(!room)
				room = load_object(file);
			if(!room)
				continue;
			if(!undefinedp(room->query("exits")[dirs[dir]]))
			{
				tell_room(room,sprintf("ֻ����һ��֨֨�¸¡����죬%s���ʯ������ˡ�\n\n",
					to_chinese(dirs[dir])));
				room->delete(sprintf("exits/%s",dirs[dir]));
			}
		}
	}
	call_out("come_tongren",3,me);
}

protected void come_tongren(object me)
{
	int stage = this_object()->query_stage();
	object tr,htr;

	if(!me || environment(me) != this_object())
		return;

	tr = new(__DIR__"npc/tongren");
		tr->move(this_object());
	htr = new(__DIR__"npc/hide_tongren");
		htr->move(this_object());

	tr->init_skill(stage);
	htr->init_skill(stage);

	tell_object(me,sprintf("\nֻ����һ���¡¡�ľ��죬����ǡ�ͭ���󡻵Ļ��ط����ˣ���\n\n
���ܵ��ұ���¶���˺ü������ף���������ɫ��%s���ұ������˳�����\n\n\n",tr->name()));

	tr->do_begin(me);
	tr->kill_ob(me);
}

void do_pass(object me)
{
	object *obs,room;
	string dir,f;
	int kee;

	if(!me || environment(me) != this_object())
		return;

	obs = filter_array(all_inventory(this_object()) - ({ me }),(: !userp($1) :));
	obs -= ({0});

	if(sizeof(obs))
		foreach(object ob in obs)
			destruct(ob);

	if(!room = find_object(f=this_object()->query_out_file()))
		room = load_object(f);
	if(!room)
		return;

	tell_object(me,"\n��֪�δ�����һ���ߺ������������ء���������\n\n");
	tell_room(this_object(),sprintf("\nֻ����һ��֨֨�¸¡����죬%s��ʯ���ϵ�һ��ʯ���ƿ��ˣ�¶����һ�����ڡ�\n\n",
		to_chinese(dir = this_object()->query_out())));
	this_object()->set(sprintf("exits/%s",dir),f);

	if(this_object()->query_stage() < 3)
	{
		tell_room(room,sprintf("\nֻ����һ��֨֨�¸¡����죬%s��ʯ���ϵ�һ��ʯ���ƿ��ˣ�¶����һ�����ڡ�\n\n",
			to_chinese(dirs[dir]) ) );
		room->set(sprintf("exits/%s",dirs[dir]),base_name(this_object()));
	}
	me->set_temp("pass_tongren",this_object()->query_stage());

	if(this_object()->query_stage() == 3)
	{
		me->set("eff_kee",(kee = me->query("max_kee")));
		me->set("kee",kee);
		tell_object(me,"\n��ֻ������һ��ů��ע�����ڣ�����˵�����������\n\n");
	}

	call_out("do_check",8,me);
}

protected void do_check(object me)
{
	if(!me || environment(me) != this_object())
		return;

	tell_object(me,"\n��ֻ����һ��ǿ��������������˳�ȥ��\n\n");
	me->move(this_object()->query_out_file());
	if(this_object()->query_stage() == 3)
		this_object()->delete("exits");
}
