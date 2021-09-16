// Room: /d/path3/k_h14.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条土路，路的两边都是一些土疙瘩，每走一步都带起
不少尘土，你不禁用手捂住鼻子，紧倒了几步。东南面一座高山
映入眼帘。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"k_h15",
  "north" : __DIR__"k_h13",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
