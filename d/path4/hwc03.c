// Room: /d/path4/hwc03.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc04",
  "east" : __DIR__"hwc02",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
