// Room: /d/jinghai/guodao2.c

inherit ROOM;

void create()
{
	set("short", "后院过道");
	set("long", @LONG
这是一间什麽也没有的空房间。


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"dating",
  "east" : __DIR__"laofang",
]));
	set("outdoors", "jinghai");

	setup();
	replace_program(ROOM);
}
