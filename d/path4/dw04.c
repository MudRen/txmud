// Room: /d/path4/dw04.c

inherit ROOM;

void create()
{
	set("short", "毛公嘴");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"dw05",
  "east" : __DIR__"dw03",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
