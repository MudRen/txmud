// Room: /d/path4/hwc20.c

inherit ROOM;

void create()
{
	set("short", "碎石路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hwc19",
  "north" : __DIR__"hwc21",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
