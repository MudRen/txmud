// Room: /d/path4/cd10.c

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"cd09",
  "southeast" : __DIR__"cd11",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
