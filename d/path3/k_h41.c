// Room: /d/path3/k_h41.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h42",
  "north" : __DIR__"k_h40",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
