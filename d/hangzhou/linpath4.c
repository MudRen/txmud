// Room: /d/hangzhou/linpath4.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你正走在一条整齐的石子路上，路虽然不很宽，但清扫的很
是干净，这里向东是林家少爷的卧房。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"linpath5",
  "east" : __DIR__"linchild",
  "north" : __DIR__"linbackroom",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
