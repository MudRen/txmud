// Room: /d/fengtian/shu.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jjf5",
]));

	setup();
	replace_program(ROOM);
}
