// Room: /d/path4/cd18.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cd19",
  "north" : __DIR__"cd17",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
