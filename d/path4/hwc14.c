// Room: /d/path4/hwc14.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"hwc15",
  "southeast" : __DIR__"hwc13",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
