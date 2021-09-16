// Room: /d/path2/hetao1.c

inherit ROOM;

void create()
{
	set("short", "河套");
	set("long", @LONG
这就是黄河的河套处。千百年来，汹涌的河水携带着滚滚的
黄沙经由这个几字形穿过黄土平原向大海奔腾而去。你站在岸边
不远处，心中升起一股豪情。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_t20",
  "east"  : __DIR__"hetao2",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
