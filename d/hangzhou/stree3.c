// Room: /d/hangzhou/stree3.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"spath3",
  "west" : __DIR__"spath1",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
