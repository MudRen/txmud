// Room: /d/path4/cd02.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cd01",
  "east" : __DIR__"cd03",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
