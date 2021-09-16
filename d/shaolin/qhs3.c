// Room: /d/shaolin/qhs3.c

inherit ROOM;

void create()
{
	set("short", "后山");
	set("long", @LONG
这里是少室山的后山，东北面是一处宏大的寺庙，那就是名
满武林的少林寺了，东面是一片茂密的灌木丛。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"qsl/exit",
]));

	setup();
	replace_program(ROOM);
}
