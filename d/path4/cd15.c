// Room: /d/path4/cd15.c

inherit ROOM;

void create()
{
	set("short", "山石路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"cd14",
  "southeast" : __DIR__"cd16",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
