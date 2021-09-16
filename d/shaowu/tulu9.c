// Room: /d/shaowu/tulu9.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tulu8",
  "east" : __DIR__"wang",
  "north" : __DIR__"tulu10",
]));

	setup();
	replace_program(ROOM);
}
