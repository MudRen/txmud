// Room: /wiz/louth/k/kai31.c

inherit ROOM;

void create()
{
	set("short", "沐浴池");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai143",
]));

	setup();
	replace_program(ROOM);
}
