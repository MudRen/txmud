// Room: /d/shaowu/roupu.c

inherit ROOM;

void create()
{
	set("short", "肉铺");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tulu5",
]));

	setup();
	replace_program(ROOM);
}
