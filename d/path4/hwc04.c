// Room: /d/path4/hwc04.c

inherit ROOM;

void create()
{
	set("short", "飞凤坡");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc05",
  "east" : __DIR__"hwc03",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
