// Room: /d/path4/hwc12.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc13",
  "east" : __DIR__"hwc11",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
