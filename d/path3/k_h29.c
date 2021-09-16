// Room: /d/path3/k_h29.c

inherit ROOM;

void create()
{
	set("short", "林荫路");
	set("long", @LONG
这是一条林荫路。江南的树林和北方的比明显不同，绿中更
露出一种生机。由于气候湿润，路上很少有尘土。北面不远就是
过江的渡口了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h30",
  "north" : __DIR__"k_h28",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
