// Room: /d/path4/hwc28.c

inherit ROOM;

void create()
{
	set("short", "山石路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"hwc29",
  "east" : __DIR__"hwc27",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
