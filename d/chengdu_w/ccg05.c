// Room: /d/path5/ccg05.c

inherit ROOM;

void create()
{
	set("short", "碎石大路");
	set("long", @LONG
你走在一条用碎石铺成的大路上，路面十分平整。路的一边
是庄稼地，另一边则是高低不齐的山岭，还有一些草屋零散的分
布，像是当地农民的住所。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg06",
  "east" : __DIR__"ccg04",
]));
        set("outdoors", "chengdu_w");
//        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
