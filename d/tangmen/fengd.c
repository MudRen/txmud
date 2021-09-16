// Room: /d/tangmen/fengd.c

inherit ROOM;

protected int nut = 3;
protected string ll = "������һƬ�Ͱ��Ĺ�ľ�ԣ���������һ�ֵ��������㣬����
�չȣ����ŵ����ķҷ�֮���������Ŀ�������";

string query_long()
{
	if(nut <= 0)
		return ll+"\n";
	return ll+"���л����ż�����\nɫ��[С����]��\n";
}

string query_item_desc()
{
	if(nut > 0)
		return "����һ��Сָ�׸Ǵ����ɫ���ӣ��ɰ�
������ֻ������ժ(pick)����������\n";

	return 0;
}

void reset()
{
	if(nut < 3)
		nut = 3;
	::reset();
}

void init()
{
	add_action("do_pick", "pick");
}

int do_pick(string arg)
{
	object ob, me = this_player();
	mapping q;

	if(arg != "����" && arg != "С����")
		return notify_fail("��Ҫժʲô��\n");

	if(nut <= 0)
		return notify_fail(sprintf("����û��%s��\n", arg));

	if(!mapp(q = me->query("quest/tangmen_quest")) || (q["name"] != "������") || q["get_nut"])
		return notify_fail("��ûС�ı���ľ�ϵ�С������һ�£��۵øϽ��������֡�\n");

	nut--;
	message_vision("$NС�������ժ����һ��С���ӡ�\n", me);

	ob = new(__DIR__"obj/nut");

	if(!ob->move(me) && !ob->move(this_object()))
		destruct(ob);

	q["get_nut"] = 1;
	return 1;
}
