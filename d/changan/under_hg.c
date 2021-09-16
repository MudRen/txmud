// Room: /d/changan/under_hg.c

inherit ROOM;

string link_room = "/d/huanggong/tj_room";

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"didao/exit",
]));

	setup();
}

void init()
{
	add_action("do_push",({ "push" }) );
}

int do_push(string arg)
{
	object room, me = this_player();

	if(!arg || arg == "")
		return notify_fail("��Ҫ��ʲô��\n");
	if(arg != "muban" && arg != "ľ��")
		return notify_fail("��Ҫ��ʲô��\n");

	if(query("exits/up"))
		return notify_fail("ľ���Ѿ����ƿ��ˡ�\n");

	if(!room = find_object(link_room))
		room = load_object(link_room);
	if(!room)
		return notify_fail("������������ľ�壬���Ǻ��޷�Ӧ��\n");

	message_vision("$N�ƿ�ľ�壬¶����һ�����ϵĳ��ڡ�\n",me);
	set("exits/up",link_room);

	room->set("exits/down",base_name(this_object()));
        message("vision","���˴������ƿ��˴��塣\n",room);
        call_out("close_ban",6);
        return 1;
}

void close_ban()
{
	object room;

	if(!query("exits/up"))
		return;

	room = find_object(link_room);
	if(!room)
		room = load_object(link_room);

        message("vision","ľ�������˻�ȥ����ס�����ϵĳ��ڡ�\n",this_object());
        message("vision","���������˻�ȥ����ס�����µĳ��ڡ�\n",room);

        room->delete("exits/down");
        delete("exits/up");
}
