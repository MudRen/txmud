// Room: /d/path3/k_s2.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
这里是开封城南门外的大路，路的两边叫卖的声音此起彼伏，
一些小孩跑来跑去正在戏耍。北面不远就是开封城了，往南一直
通向驻马店。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s3",
  "north" : __DIR__"k_s1",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}