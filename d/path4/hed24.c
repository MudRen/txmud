// Room: /d/path4/hed24.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hed25",
  "east" : __DIR__"hed23",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
