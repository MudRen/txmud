// Room: /d/shaolin/tulu1.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
一条坑坑洼洼的土路在你脚下延伸着，天气好的时候这里漫
天的黄土。阴雨天时这里又泥泞不堪，附近的村民没有钱来修路，
只好凑合着这样。
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tulu2",
  "northwest" : __DIR__"xiaolu4",
]));

	setup();
	replace_program(ROOM);
}
