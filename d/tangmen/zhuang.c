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
		message_vision("$N一个没站稳，倒栽冲摔了下去。\n", me);
		me->receive_damage("kee", n>25?25:n, "trip");
		me->move(__DIR__"lianwu");
		tell_room(environment(me), me->name()+"摔了下来。\n", ({me}));
		return;
	}

	message_vision("$N扎了个马步，纹丝不动。\n", me);
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
