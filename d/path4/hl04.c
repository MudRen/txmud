// Room: /d/path4/hl04.c

inherit ROOM;

void create()
{
	set("short", "花林");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hl05",
  "north" : __DIR__"hl03",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
