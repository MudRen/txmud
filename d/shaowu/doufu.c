// Room: /d/shaowu/doufu.c

inherit ROOM;

void create()
{
	set("short", " 豆腐房");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"tulu10",
]));

	setup();
	replace_program(ROOM);
}
