// Room: /d/path4/hwc15.c

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"hwc16",
  "southeast" : __DIR__"hwc14",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
