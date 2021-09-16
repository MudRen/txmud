// Room: /d/changan/under_hg.c

inherit ROOM;

string link_room = "/d/huanggong/tj_room";

void create()
{
	set("short", "地道");
	set("long", @LONG
这是一间什麽也没有的空房间。
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
		return notify_fail("你要推什么？\n");
	if(arg != "muban" && arg != "木板")
		return notify_fail("你要推什么？\n");

	if(query("exits/up"))
		return notify_fail("木板已经被推开了。\n");

	if(!room = find_object(link_room))
		room = load_object(link_room);
	if(!room)
		return notify_fail("你试着推了推木板，但是毫无反应。\n");

	message_vision("$N推开木板，露出了一个向上的出口。\n",me);
	set("exits/up",link_room);

	room->set("exits/down",base_name(this_object()));
        message("vision","有人从下面推开了床板。\n",room);
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

        message("vision","木板又移了回去，盖住了向上的出口。\n",this_object());
        message("vision","床板又移了回去，盖住了向下的出口。\n",room);

        room->delete("exits/down");
        delete("exits/up");
}
