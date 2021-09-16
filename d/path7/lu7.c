// Room: /d/path7/lu7.c

inherit ROOM;

void create()
{
	set("short", "黄土小路");
	set("long", @LONG
这是一条清静的小路，虽说离大路不远，却是少见人迹，地
上零星的长着一些小草，看样子很少有人走过这里。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"lu8",
  "northwest" : __DIR__"lu6",
]));

	set("outdoors", "path7");

	setup();
	replace_program(ROOM);
}
