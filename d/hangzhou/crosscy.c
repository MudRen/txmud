// Room: /d/hangzhou/crosscy.c

inherit ROOM;

void create()
{
	set("short", "路口");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yongningn3",
  "east" : __DIR__"changanw3",
]));

	setup();
	replace_program(ROOM);
}
