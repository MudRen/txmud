// Room: /d/jinghai/gui11.c

inherit ROOM;

void create()
{
	set("short", "西码头");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"gui20",
  "east" : __DIR__"gui9",
]));

	setup();
	replace_program(ROOM);
}
