// Room: /d/jinghai/lukou.c

inherit ROOM;

void create()
{
	set("short", "土路岔口");
	set("long", @LONG
这是一间什麽也没有的空房间。



LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"xiaolu1",
  "southwest" : __DIR__"muqiao",
  "east" : __DIR__"matou1",
  "west" : __DIR__"shulin3",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
