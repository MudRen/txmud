// Room: /d/path4/cd04.c

inherit ROOM;

void create()
{
	set("short", "蜀关口");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cd03",
  "southeast" : __DIR__"cd05",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
