// Room: /d/path3/k_h42.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k_h41",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
