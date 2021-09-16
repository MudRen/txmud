// Room: /wiz/louth/a/caodi1.c

inherit ROOM;

void create()
{
	set("short", "悬崖底");
	set("long", @LONG
这里是悬崖的底部，眼前是一面是陡直的石壁通向上面，地
上长满了半人高的蒿草。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yu70",
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

	if(arg != "悬崖")
		return 0;

	message_vision("$N顺着悬崖爬了上去。。。\n\n",me);
	me->start_busy(6);
	call_out("greeting",5,me);
        return 1;
}

void greeting(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;
	message_vision("$N累的气喘吁吁，爬到了一个山洞的入口处。\n",me);
	me->move(__DIR__"shandong1");
}
