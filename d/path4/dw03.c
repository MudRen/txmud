// Room: /d/path4/dw03.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dw04",
  "east" : __DIR__"dw02",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
