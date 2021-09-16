// Room: /d/huanggong/tj_room.c

inherit ROOM;

string link_room = "/d/changan/under_hg";

void create()
{
	set("short", "太监房");
	set("long", @LONG
这是一间空空荡荡的房间，除了屋子中间的一张光板大床外
什么也没有，床板已经被磨得发亮。这里显然是太监休息的地方。
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
		return notify_fail("你要推什么？\n");
	if(arg != "chuangban" && arg != "床板")
		return notify_fail("你要推什么？\n");

	if(query("exits/up"))
		return notify_fail("床板已经被推开了。\n");

	if(!room = find_object(link_room))
		room = load_object(link_room);
	if(!room)
		return notify_fail("你试着推了推床板，但是毫无反应。\n");

	message_vision("$N推开床板，露出了一个向下的出口。\n",me);
	set("exits/down",link_room);

	room->set("exits/up",base_name(this_object()));
        message("vision","有人从上面推开了木板。\n",room);
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

        message("vision","床板又移了回去，盖住了向下的出口。\n",this_object());
        message("vision","木板又移了回去，盖住了向上的出口。\n",room);

        room->delete("exits/up");
        delete("exits/down");
}
