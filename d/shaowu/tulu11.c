// Room: /d/shaowu/tulu11.c

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
  "south" : __DIR__"shijing",
  "east" : __DIR__"tiejiang",
  "north" : __DIR__"tulu12",
]));

	setup();
	replace_program(ROOM);
}
