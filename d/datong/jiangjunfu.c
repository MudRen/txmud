// Room: /open/dt/jiangjunfu.c

inherit ROOM;

void create()
{
	set("short", "将军府");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jinyangjie5",
]));

	setup();
	replace_program(ROOM);
}
