// Room: /d/path2/q2.c

inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
这是一处破败的小院落，石块堆叠的院墙有好几处已经倒塌
了，院子里的地上到处是随石块和蒿草。但是通向正房的地上很
少有杂草，好像常有人走似的，很让人奇怪。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"q3",
  "south" : __DIR__"q1",
]));

	setup();
	replace_program(ROOM);
}
