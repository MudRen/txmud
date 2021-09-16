// Room: /d/shaowu/tulu4.c

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
  "west" : __DIR__"caodi",
  "south" : __DIR__"tulu3",
  "north" : __DIR__"tulu5",
]));

	setup();
	replace_program(ROOM);
}
