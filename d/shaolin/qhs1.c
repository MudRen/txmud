// Room: /d/shaolin/qhs1.c

inherit ROOM;

void create()
{
	set("short", "后山");
	set("long", @LONG
这里是少室山的后山，东北面是一处宏大的寺庙，那就是名
满武林的少林寺了，西面是一条蜿蜒的小径通向远方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"qhs2",
  "northeast" : __DIR__"houshan2",
]));

	setup();
	replace_program(ROOM);
}
