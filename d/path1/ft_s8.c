// Room: /d/path1/ft_s8.c

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
这是一条林中小路，两旁草地上长满了各式各样的野花。林
间的松树上结满了松果，不时传来阵阵清香。南面一条林间小路
若隐若现。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"zjz17",
  "west" : __DIR__"ft_s7",
  "east" : __DIR__"ft_s9",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
