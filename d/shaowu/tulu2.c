// Room: /d/shaowu/tulu2.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tulu3",
  "south" : __DIR__"tulu1",
  "east" : __DIR__"tulu8",
  "north" : __DIR__"shuichan",
]));

	setup();
	replace_program(ROOM);
}
