// Room: /d/path4/hed26.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hed27",
  "east" : __DIR__"hed25",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
