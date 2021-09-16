// Room: /d/hangzhou/scross.c

inherit ROOM;

void create()
{
	set("short", "岔路口");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"spath2",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
