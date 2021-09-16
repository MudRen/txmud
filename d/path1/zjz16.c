// Room: /d/path1/zjz16.c

inherit ROOM;

void create()
{
	set("short", "林间小土路");
	set("long", @LONG
这是一条林中小路，两旁草地上长满了各式各样的野花。林
间的松树上结满了松果，不时传来阵阵清香。风儿吹来，你有种
找不到方向的感觉。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"zjz17",
  "southeast" : __DIR__"zjz15",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
