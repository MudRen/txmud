// Room: /d/path4/tree02.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tree01",
  "east" : __DIR__"tree03",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
