// Room: /d/hangzhou/zfpath3.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条小路可以一直通到一个荷花塘，小路的东面就是府
衙的正门了，小路的西侧是府衙的围墙，另一侧是一个美丽的花
园。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"zfhetang",
  "east" : __DIR__"zfyuanzi",
  "north" : __DIR__"zfgarden",
]));

	setup();
	replace_program(ROOM);
}
