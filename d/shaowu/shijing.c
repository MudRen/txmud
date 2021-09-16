// Room: /d/shaowu/shijing.c

inherit ROOM;

void create()
{
	set("short", "石井");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"tulu10",
  "west" : __DIR__"tulu7",
  "east" : __DIR__"tulu13",
  "north" : __DIR__"tulu11",
]));

	setup();
	replace_program(ROOM);
}
