// Room: /d/path4/hwc34.c

inherit ROOM;

void create()
{
	set("short", "蜀中官道");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/chengdu/out_chengdu_n",
  "north" : __DIR__"hwc33",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
