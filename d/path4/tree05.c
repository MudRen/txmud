// Room: /d/path4/tree05.c

inherit ROOM;

void create()
{
	set("short", "山林小路");
	set("long", @LONG
这是一间什麽也没有的空房间。


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"tree04",
  "east" : __DIR__"hed13",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
