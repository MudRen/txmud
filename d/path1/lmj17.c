// Room: /d/path1/lmj17.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条山边的小道，再向北就到了虎峪山下。一只秃鹰从
你头顶飞过，你心里不禁涌起一丝不安。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"lmj16",
  "northup" : __DIR__"py2",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
