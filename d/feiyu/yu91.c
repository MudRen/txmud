// Room: /u/w/wangs/a/yu91.c

inherit ROOM;

void create()
{
    set("short", "看雨轩");
	set("long", @LONG
这是一间清幽的小舍，舍内一尘不染，看来常常有人来这里
打扫。每逢风雨来袭，轩内顿作萧瑟之音，故美其名曰“看雨轩”。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yu90",
]));

	setup();
	replace_program(ROOM);
}

