// patroling.c

inherit ROOM;

void init()
{
	object ob;
	string *p;

	if((ob = previous_object())
	&& userp(ob)
	&& ob->query("class") == "rain"
	&& sizeof(p = ob->query("patroling/path"))
	&& member_array(file_name(this_object()),p) != -1)
	{
		ob->set("patroling/time",time());
		call_out("come_on",1,ob);
	}
}

void come_on(object ob)
{
	if(!ob || environment(ob) != this_object())
		return;

	tell_object(ob,"\n�����������ʼ�Ĵ�Ѳ������������\n");
	call_out("end_patroling",10+random(6),ob);
}

void end_patroling(object who)
{
	string *p,f;

	if(!who || environment(who) != this_object())
		return;

	tell_object(who,"\n������Ѳ����һ����û����ʲô�쳣���顣\n");
	who->delete("patroling/time");
	if(sizeof(p=who->query("patroling/path"))
	&& member_array((f=file_name(this_object())),p) != -1 )
		p -= ({f});
	who->set("patroling/path",p);
	if(!sizeof(p))
	{
		who->set("quest/rain_quest/finish",1);
		tell_object(who,"\n���Ѿ���������Ѳ������\n");
	}
	who->delete("patroling/time");
}

int valid_leave(object who,string dir)
{
	int time;
	string *p,f;

	if((time = who->query("patroling/time")))
	{
		if(time() - time >= 4)
		{
			tell_object(who,"\n������Ѳ����һ����û����ʲô�쳣���顣\n");
			who->delete("patroling/time");
			if(sizeof(p=who->query("patroling/path"))
			&& member_array((f=file_name(this_object())),p) != -1 )
				p -= ({f});
			who->set("patroling/path",p);
			if(!sizeof(p))
			{
				who->set("quest/rain_quest/finish",1);
				tell_object(who,"\n���Ѿ���������Ѳ������\n");
			}
		}
		who->delete("patroling/time");
	}

	return room::valid_leave(who,dir);
}
