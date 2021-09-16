// Room: /wiz/louth/a/yu70.c

inherit ROOM;

void create()
{
	set("short", "悬崖底");
	set("long", @LONG
你的面前是一座笔直的山峰，高若千丈，峰顶在云雾中
隐约可见，崖势略缓，有几根长长的蔓藤从悬崖上垂下，东
面是一片青青草地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"caodi1",
  "south" : __DIR__"yu69",
]));
	set("outdoors","feiyu");
	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me = this_player();

	if(arg != "悬崖" && arg != "cliff")
		return 0;

	message_vision("$N抓住悬崖上的蔓藤，往上爬去。。。\n",me);
	me->start_busy(6);
	call_out("greeting",6,me);
	return 1;
}

void greeting(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	message_vision("$N纵身一跳，终于爬上了悬崖。\n",me);
        me->stop_busy();
	me->move(__DIR__"yu63");
}
