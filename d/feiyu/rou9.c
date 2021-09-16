// Room: /wiz/louth/a/rou9.c

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
  "east" : __DIR__"rou10",
  "west" : __DIR__"rou8",
]));

	setup();
	replace_program(ROOM);
}
