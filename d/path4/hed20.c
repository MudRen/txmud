// Room: /d/path4/hed20.c

inherit ROOM;

void create()
{
	set("short", "山林小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hed21",
  "north" : __DIR__"hed19",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
