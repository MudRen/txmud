// Room: /d/path4/hed13.c

inherit ROOM;

void create()
{
	set("short", "清水湾");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tree05",
  "east" : __DIR__"hed12",
  "south" : __DIR__"hed14",
  "north" : __DIR__"hl06",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
