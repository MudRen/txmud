// Room: /d/shaowu/gengdi.c

inherit ROOM;

void create()
{
	set("short", "耕地");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tulu6",
]));

	setup();
	replace_program(ROOM);
}
