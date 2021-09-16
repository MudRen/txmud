// Room: sg_dong2.c

inherit ROOM;

void create()
{
        set("short", "不知名山洞");
        set("long", @LONG
你从洞口一直向下滑，因为洞是斜的，所以你根本无法停下
来。一会，你身下一空，跌在了一团干草上。这是一个天然的山
洞，洞里倒也干爽，你身子下面有一些干草。洞口被「松枝」遮
掩透进几缕微光。
LONG
);
	set("objects", ([
            __DIR__"master/master-feng":1,
]));

	set("item_desc",([
	"松枝" : "几枝粗大的松树枝遮住了洞口，抓(hold)着它也许能爬上悬崖。\n"
]));
	setup();
}

void init()
{
	add_action("do_out","hold");
}

int do_out(string arg)
{
	object me = this_player();

	if(arg != "松枝")
		return notify_fail("你要抓住什么？\n");

	message_vision("$N攀着老松树枝向上爬了出去。\n", me);

	if( me->move(__DIR__"laosong") )
		tell_room(environment(me), me->name() + "从下面爬了上来。\n",({me}));
	return 1;
}

