// Room: /d/path4/cd13.c

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cd14",
  "north" : __DIR__"cd12",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
