// Room: /wiz/louth/a/yaxinroom.c

inherit ROOM;

void create()
{
	set("short", "雅馨居");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road6",
  "north" : __DIR__"neishi",
]));

	setup();
	replace_program(ROOM);
}
