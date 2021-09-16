// Room: /d/shaowu/tulu8.c

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
  "west" : __DIR__"tulu2",
  "east" : __DIR__"tulu9",
]));

	setup();
	replace_program(ROOM);
}
