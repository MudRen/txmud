// kuangkeng.c

private void finish_mine(object who);

void init()
{
	add_action("do_cai","cai");
}

int do_cai(string arg)
{
	object me = this_player();

	if( stringp(arg) && (arg != "��ʯ") )
		return notify_fail("��Ҫ��ʲô��\n");

	if( me->query("kee") <= 20 )
		return notify_fail("���Ѿ��ۻ��ˣ���Ҳû�������ɿ��ˡ�\n");

	me->start_busy(10);
	message_vision("$N�����ͷ���ſ�ӵײ�����������������\n",me);
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
		tell_object(who,"���ʲôҲû�ҳ�����\n");
		who->stop_busy();
		return;
	}

	ob = new(__DIR__"obj/iron_stone");
	tell_object(who,sprintf("������һ��%s��\n",ob->name()));
	ob->move(this_object());
	ob->set_master(geteuid(who));

	who->stop_busy();
	who->receive_damage("kee",15,"tire");
	return;
}
