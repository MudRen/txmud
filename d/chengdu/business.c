// Room: /wiz/louth/c/shangzhan.c

inherit ROOM;

void create()
{
	set("short", "商栈");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jguanlu7",
]));

	setup();
	replace_program(ROOM);
}
