// Room: /d/path4/hwc21.c

inherit ROOM;

void create()
{
	set("short", "长江中游渡口南岸");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hwc20",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
