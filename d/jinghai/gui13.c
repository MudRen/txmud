// Room: /d/jinghai/gui13.c

inherit ROOM;

void create()
{
	set("short", "弟子休息室");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"gui4",
]));

	setup();
	replace_program(ROOM);
}
