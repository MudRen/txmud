// Room: /d/path4/hwc05.c

inherit ROOM;

void create()
{
	set("short", "林荫路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hwc06",
  "east" : __DIR__"hwc04",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
