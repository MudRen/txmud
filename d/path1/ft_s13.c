// Room: /d/path1/ft_s13.c

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
这是一条林中小路，两旁草地上长满了各式各样的野花。林
间的松树上结满了松果，不时传来阵阵清香。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ft_s12",
  "north" : __DIR__"ft_s14",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
