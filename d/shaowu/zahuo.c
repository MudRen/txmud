// Room: /d/shaowu/zahuo.c

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tulu12",
]));

	setup();
	replace_program(ROOM);
}
