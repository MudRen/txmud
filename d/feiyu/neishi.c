// Room: /wiz/louth/a/neishi.c

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
这是一间布置简单的房间，中间是一张八仙桌，周围整齐的
摆放着几把椅子，靠墙放着一个柜子，房间四处打扫得干干净净。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yaxinroom",
]));
	setup();
}

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object me;
        me = this_player();
        if (arg != "柜子" && arg != "cupboard")
                return notify_fail("你要打开什么？\n");
        message_vision("$N打开柜子，发现里边竟然是一个秘道的入口。\n",me);
        set("exits/enter", __DIR__"midao1");
	call_out("do_close",8);
        return 1;
}

void do_close()
{
	if(query("exits/enter"))
	{
		delete("exits/enter");
		tell_room(this_object(),"出口轻轻的掩上了。\n");
	}
}
