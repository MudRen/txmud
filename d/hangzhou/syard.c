// Room: /d/hangzhou/syard.c

inherit ROOM;

void create()
{
	set("short", "空地");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sforest",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
