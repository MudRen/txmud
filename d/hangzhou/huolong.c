// Room: /d/hangzhou/huolong.c

inherit ROOM;

void create()
{
	set("short", "火龙庙");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"sforest",
  "east" : __DIR__"smishi1",
  "north" : __DIR__"spath5",
]));

	setup();
	replace_program(ROOM);
}
