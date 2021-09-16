// Room: /d/path3/k_s5.c

inherit ROOM;

void create()
{
	set("short", "林荫路");
	set("long", @LONG
这里是一片树林，林中一条小路蜿蜒向前，不时传来阵阵鸣
叫，分不出是什么动物。你不由得加快了脚步。由此向此就到驻
马店了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s6",
  "north" : __DIR__"k_s4",
]));

	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
