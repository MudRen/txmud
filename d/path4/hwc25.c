// Room: /d/path4/hwc25.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc26",
  "northeast" : __DIR__"hwc24",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
