// Room: /d/chengdu/hy.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这是一个寂静的小院子，四处打扫得干干净净，中间一个磨
盘，北墙根底下摆着几个石蹲。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"minjv",
]));

	set("outdoors", "chengdu");

	set("cannot_build_home", 1);

	setup();
	replace_program(ROOM);
}
