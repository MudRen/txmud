// Room: /open/dt/wanhualou.c

inherit ROOM;

void create()
{
	set("short", "万花楼");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"youfujie1",
]));

	setup();
	replace_program(ROOM);
}
