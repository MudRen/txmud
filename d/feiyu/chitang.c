// Room: /d/feiyu/chitang.c

inherit ROOM;

void create()
{
	set("short", "小池塘");
	set("long", @LONG
这是一处小小的池塘，池塘里的水清澈见底。经常能看见绯
雨阁的弟子拿着水桶来这里打(fill)水去浇花。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"yu16",
]));

	set("outdoors","feiyu");
	setup();
}

void init()
{
	add_action("do_fill","fill");
}

int do_fill(string arg)
{
	object me = this_player(),ob;

	if(!objectp(ob = present("water bucket",me)) || !ob->id(arg))
		return notify_fail("你要用什么打水？\n");

	if(ob->is_full())
		return notify_fail("水桶已经是满的了。\n");

	message_vision("$N拿起水桶在池塘里打了满满的一桶清水。\n",me);
	ob->set_full(1);
	return 1;
}
