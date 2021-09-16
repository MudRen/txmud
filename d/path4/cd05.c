// Room: /d/path4/cd05.c

inherit ROOM;

void create()
{
	set("short", "崎岖山路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"cd04",
  "southeast" : __DIR__"cd06",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
