// Room: /d/path4/hwc31.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hwc32",
  "north" : __DIR__"hwc30",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
