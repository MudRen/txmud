// Room: /d/path4/hed23.c

inherit ROOM;

void create()
{
	set("short", "伏象坡");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hed24",
  "north" : __DIR__"hed22",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
