// Room: /d/path4/cd16.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"cd15",
  "south" : __DIR__"cd17",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
