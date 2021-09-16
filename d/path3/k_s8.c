// Room: /d/path3/k_s8.c

inherit ROOM;

void create()
{
	set("short", "林荫路");
	set("long", @LONG
这里是一片树林，林中一条小路曲曲弯弯。林中的草地已经
被踏得歪七捌八，偶尔有吹柴的农夫路过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s9",
  "north" : __DIR__"k_s7",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
