// top.c
// by Find.

protected int make_leader, jiange = 3600;

protected object enter, leader;

int check_rooms();

protected void refresh_me()
{
	object env;
	string file;
	int i;

	if(objectp(leader))
	{
		if(env = environment(leader))
			tell_object(env, sprintf("\n%s����һ���������ˡ�\n\n", leader->name()));
		destruct(leader);
	}

	if(enter)
	{
		enter->set_is_enter(0);	// enter �Լ��������
		enter = 0;
	}

	for(i=0;i<9;i++)
	{
		file = sprintf(__DIR__"down%d", 1+i);
		if(env = find_object(file))
			destruct(env);
	}

	//make_leader = 0;
}

protected void select_enter()
{
	object ob,room;
	int i;
	string file;

	while(!enter)
	{
		file = sprintf(__DIR__"top%d", 1+random(9));
		if( objectp(enter = find_object(file)) || objectp(enter = load_object(file)) )
			enter->set_is_enter(1);
	}

	if( objectp(room = find_object(file=__DIR__"down1"))
	|| objectp(room = load_object(file)) )
	{
		for(i=0;i<2;i++)
		{
			ob = new(__DIR__"npc/tufei");
			ob->move(room);
		}
	}

	if( objectp(room = find_object(file=__DIR__"down4"))
	|| objectp(room = load_object(file)) )
	{
		ob = new(__DIR__"npc/tufei");
		ob->move(room);
	}

	if( objectp(room = find_object(file=__DIR__"down5"))
	|| objectp(room = load_object(file)) )
	{
		ob = new(__DIR__"npc/tufei");
		ob->move(room);
	}

	if( objectp(room = find_object(file=__DIR__"down9"))
	|| objectp(room = load_object(file)) )
	{
		for(i=0;i<3;i++)
		{
			ob = new(__DIR__"npc/tufei");
			ob->move(room);
		}

		ob = new(__DIR__"npc/toumu");
		ob->move(room);
	}
}

void query_leader()
{
	object room;
	int time = time();

	if( (time - make_leader < jiange) || !check_rooms() )
		return;

	while(!leader)
	{
		string file = sprintf(__DIR__"fengd%d", 1+random(9));
		if( objectp(room = find_object(file)) || objectp(room = load_object(file)) )
		{
			leader = new(__DIR__"npc/keyman");
			if(!leader->move(room))
			{
				destruct(leader);
				continue;
			}
			else
			{
				tell_room(room, "��Ȼ��֪�����������һ����վ���������ǰ��\n");
				make_leader = time();
				call_out("select_enter", 3);
			}
		}
	}
}

protected int have_person(object room)
{
	if(!room)
		return 0;
	return sizeof(filter_array(all_inventory(room),(: userp :)));
}

int check_rooms()
{
	int i;
	string file;
	object room, ob = previous_object();

	if(ob && !in_same_dir(file_name(ob), __FILE__))
		return 0;

	for(i=0;i<9;i++)
	{
		file = sprintf(__DIR__"down%d", 1+i);
		if(!objectp(room = find_object(file)))
			continue;
		if(have_person(room))
			return 0;
	}

	refresh_me();
	return 1;
}

protected void reset()
{
	if(time() - make_leader < jiange)
		return 0;

	check_rooms();
}
