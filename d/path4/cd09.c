// Room: /d/path4/cd09.c

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cd08",
  "southeast" : __DIR__"cd10",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
