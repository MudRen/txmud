// Room: /d/path4/hed16.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hed17",
  "north" : __DIR__"hed15",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
