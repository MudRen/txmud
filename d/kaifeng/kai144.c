// Room: /u/w/wangs/b/kai144.c

inherit ROOM;

void create()
{
	set("short", "开封东街");
	set("long", @LONG
这条大街横贯东西，把开封城分成两半。路上行人熙熙攘攘，
很多卖冰糖葫芦的、风味小吃的小商贩们沿街叫卖，走在这条街
上，你深切感受到了俗世的繁华与喧嚣。路北边是一家客栈，南
边则是一座军营，再向东不远就是开封东门了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai146",
  "north" : __DIR__"kai145",
  "west" : __DIR__"kai141",
  "east" : __DIR__"kai147",
]));
        set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
