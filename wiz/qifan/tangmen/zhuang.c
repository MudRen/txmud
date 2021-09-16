// Room: /d/tangmen/zhuang.c

inherit ROOM;

void init()
{
	object me = this_player();

	if(!userp(me))
		return;

	call_out("show_msg", 1, me);
}

protected void show_msg(object me)
{
	int sk, n;

	if(!me || (environment(me) != this_object()))
		return;

	sk = me->query_skill("dodge", 1);

	if( ((n=me->query("kee")) <= 5) || (sk < 40) || (random(10) > (sk - 35)) )
	{
		message_vision("$Nһ��ûվ�ȣ����Գ�ˤ����ȥ��\n", me);
		me->receive_damage("kee", n>25?25:n, "trip");
		me->move(__DIR__"lianwu");
		tell_room(environment(me), me->name()+"ˤ��������\n", ({me}));
		return;
	}

	message_vision("$N���˸�������˿������\n", me);
}

int valid_leave(object ob,string dir)
{
	if(dir != "down")
	{
		ob->receive_damage("kee",20, "tire");
		ob->start_busy(2);
	}

	return 1;
}
