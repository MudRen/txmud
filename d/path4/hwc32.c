// Room: /d/path4/hwc32.c

inherit ROOM;

void create()
{
	set("short", "蜀中大道");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hwc33",
  "north" : __DIR__"hwc31",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
