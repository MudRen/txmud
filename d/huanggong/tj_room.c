// Room: /d/huanggong/tj_room.c

inherit ROOM;

string link_room = "/d/changan/under_hg";

void create()
{
	set("short", "̫�෿");
	set("long", @LONG
����һ��տյ����ķ��䣬���������м��һ�Ź�����
ʲôҲû�У������Ѿ���ĥ�÷�����������Ȼ��̫����Ϣ�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"daolu6",
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
	if(arg != "chuangban" && arg != "����")
		return notify_fail("��Ҫ��ʲô��\n");

	if(query("exits/up"))
		return notify_fail("�����Ѿ����ƿ��ˡ�\n");

	if(!room = find_object(link_room))
		room = load_object(link_room);
	if(!room)
		return notify_fail("�����������ƴ��壬���Ǻ��޷�Ӧ��\n");

	message_vision("$N�ƿ����壬¶����һ�����µĳ��ڡ�\n",me);
	set("exits/down",link_room);

	room->set("exits/up",base_name(this_object()));
        message("vision","���˴������ƿ���ľ�塣\n",room);
        call_out("close_ban",6);
        return 1;
}

void close_ban()
{
	object room;

	if(!query("exits/down"))
		return;

	room = find_object(link_room);
	if(!room)
		room = load_object(__DIR__"didao1");

        message("vision","���������˻�ȥ����ס�����µĳ��ڡ�\n",this_object());
        message("vision","ľ�������˻�ȥ����ס�����ϵĳ��ڡ�\n",room);

        room->delete("exits/up");
        delete("exits/down");
}
