// Room: /d/path4/hed10.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hed11",
  "east" : __DIR__"hed09",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
