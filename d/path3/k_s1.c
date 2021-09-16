// Room: /d/path3/k_s1.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这里是开封城南门外的大路，路的两边叫卖的声音此起彼伏，
一些小孩跑来跑去正在戏耍。北面不远就是开封城了，往南一直
通向驻马店。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"k_s2",
  "north" : "/d/kaifeng/out_kaifeng_s",
]));

	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
