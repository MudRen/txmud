// Room: /d/path4/cd14.c

inherit ROOM;

void create()
{
	set("short", "山石路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cd15",
  "north" : __DIR__"cd13",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
