// Room: /d/path4/hwc18.c

inherit ROOM;

void create()
{
	set("short", "樟岱岭");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"hwc22",
  "east" : __DIR__"hwc17",
  "north" : __DIR__"hwc19",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
