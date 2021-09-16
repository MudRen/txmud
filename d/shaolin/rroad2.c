// Room: /d/shaolin/rroad2.c

inherit ROOM;

void create()
{
	set("short", "前院过道");
	set("long", @LONG
这里是少林寺的前院过道，这里来的人不多，偶有几个小僧
匆匆忙忙的路过。在南边的小径边有一片银呆树林，树木繁荫，
盛夏时却是避暑的好去处。从这里向北是东广场，向南的过道伸
伸向远方，向东是练武场。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"rroad1",
  "east" : __DIR__"lwc_r",
  "north" : __DIR__"e_square",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
