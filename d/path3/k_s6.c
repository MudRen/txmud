// Room: /d/path3/k_s6.c

inherit ROOM;

void create()
{
	set("short", "林荫路");
	set("long", @LONG
这里是一片树林，林中一条小路曲曲弯弯。草地上长着一些
野花，一看就知道不是什么好品种。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s7",
  "north" : __DIR__"k_s5",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
