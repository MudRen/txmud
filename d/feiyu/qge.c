// Room: /wiz/louth/a/qge.c

inherit ROOM;

void create()
{
	set("short", "清音阁");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road3",
]));

	setup();
	replace_program(ROOM);
}
