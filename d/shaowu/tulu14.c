// Room: /d/shaowu/tulu14.c

inherit ROOM;

void create()
{
	set("short", "空房间");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tulu13",
  "east" : __DIR__"tianye",
  "north" : __DIR__"chitang",
]));

	setup();
	replace_program(ROOM);
}
