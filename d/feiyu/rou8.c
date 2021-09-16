// Room: /wiz/louth/a/rou8.c

inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
这是一条昏暗的地道，地道边上的墙壁里还插着一根点燃的
蜡烛，显见这里经常有人来。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"rou7",
  "east" : __DIR__"rou9",
]));

	setup();
	replace_program(ROOM);
}
