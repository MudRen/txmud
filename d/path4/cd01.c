// Room: /d/path4/cd01.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/chengdu/out_chengdu_e",
  "east" : __DIR__"cd02",
]));

	setup();
	set("outdoors", "path4");
	replace_program(ROOM);
}
