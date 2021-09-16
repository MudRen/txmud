// kuangkeng.c

private void finish_mine(object who);

void init()
{
	add_action("do_cai","cai");
}

int do_cai(string arg)
{
	object me = this_player();

	if( stringp(arg) && (arg != "矿石") )
		return notify_fail("你要采什么？\n");

	if( me->query("kee") <= 20 )
		return notify_fail("你已经累坏了，再也没有力气采矿了。\n");

	me->start_busy(10);
	message_vision("$N抡起镐头朝着矿坑底部狠命的砸了起来。\n",me);
	call_out( (: finish_mine :), (3+random(3)), me);
	return 1;
}

private void finish_mine(object who)
{
	object ob;

	if(!who || (environment(who) != this_object()))
		return;

	if(!random(6))
	{
		tell_object(who,"结果什么也没砸出来。\n");
		who->stop_busy();
		return;
	}

	ob = new(__DIR__"obj/iron_stone");
	tell_object(who,sprintf("敲下了一块%s。\n",ob->name()));
	ob->move(this_object());
	ob->set_master(geteuid(who));

	who->stop_busy();
	who->receive_damage("kee",15,"tire");
	return;
}
