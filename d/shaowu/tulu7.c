// Room: /d/shaowu/tulu7.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tulu6",
  "east" : __DIR__"shijing",
]));

	setup();
	replace_program(ROOM);
}
