// Room: /d/path4/hed14.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hed15",
  "north" : __DIR__"hed13",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
