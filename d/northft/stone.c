// stone.c
// Find.

protected int open, count;

void create()
{
	count = 3 + random(3);
}

int query_open() { return open; }

void do_push(object who)
{
	object room1, room2;

	if(!objectp(who) || open)
		return;

	if(!objectp(room1 = find_object(__DIR__"ftn11"))
	&& !objectp(room1 = load_object(__DIR__"ftn11")) )
		return;
	if(!objectp(room2 = find_object(__DIR__"ftn12"))
	&& !objectp(room2 = load_object(__DIR__"ftn12")) )
		return;

	if(--count <= 0)
	{
		count = 3 + random(3);
		open = 1;

		room1->set("exits/east", __DIR__"ftn12");
		room2->set("exits/west", __DIR__"ftn11");
		tell_object(room1, "��ʯͷ����¡��һ��������һ�ԡ�\n");	
		tell_object(room2, "��ʯͷ����¡��һ��������һ�ԡ�\n");

		if(find_call_out("do_close") >= 0)
			remove_call_out("do_close");
		call_out( "do_close", 300);
	}

	else
		tell_object(who, "��ʯͷ��˿û����\n");
}

protected void do_close()
{
	object room1, room2;

	if(!objectp(room1 = find_object(__DIR__"ftn11"))
	&& !objectp(room1 = load_object(__DIR__"ftn11")) )
		return;
	if(!objectp(room2 = find_object(__DIR__"ftn12"))
	&& !objectp(room2 = load_object(__DIR__"ftn12")) )
		return;

	room1->delete("exits/east");
	room2->delete("exits/west");

	tell_object(room1, "��ʯͷ����¡��һ��������·�м䵲ס��ȥ·��\n");	
	tell_object(room2, "��ʯͷ����¡��һ��������·�м䵲ס��ȥ·��\n");

	open = 0;
}
