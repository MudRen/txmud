// Room: /d/path1/cc_tch18.c

inherit ROOM;

void create()
{
	set("short", "沙路");
	set("long", @LONG
走到这里，你已经来到戈壁了，除了风沙和巨石，你什么也
看不到。不远的地上，散落着一些尸骨，不知死的是什么。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"cc_tch17",
  "west" : __DIR__"cc_tch19",
]));
	set("outdoors", "path1");

	set("objects",([
	RIDE_DIR"w_horse" : 1,
]));

	setup();
	replace_program(ROOM);
}
