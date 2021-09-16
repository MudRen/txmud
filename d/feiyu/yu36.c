// Room: /u/w/wangs/a/yu36.c

inherit ROOM;

void create()
{
	set("short", "寝室");
	set("long", @LONG
这里是绯雨阁的一间寝室，房中间放着一张大床(bed)。
不知平时是哪位姐姐住在这里，把整间屋子都收拾得干干
净净，整整齐齐。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yu35",
]));
        set("item_desc",([
        "bed" : "一张很大的木床。\n",
        "大床" : "一张很大的木床。\n",
]));

	setup();
}

void init()
{
        add_action("do_move","move");
}

int do_move(string arg)
{
        object me = this_player(),ob;

	if(arg != "床" && arg != "bed")
		return notify_fail("你要挪什么？\n");

	if(!me->query_temp("mark/louth_quxiao"))
		return notify_fail("你使劲挪了挪木床,但是没有挪动。\n");

        if(sizeof(filter_array(children(__DIR__"obj/creat"),(: clonep :))) > 0)
                return notify_fail("你挪开了木床,什么都没发现.\n");

	message_vision("$N把木床挪到了一边，发现床下有一个木头箱子,$N赶紧拣了起来.\n",me);
	ob = new(__DIR__"obj/creat");
	ob->move(me);
	me->delete_temp("mark/louth_quxiao");
	return 1;
}

