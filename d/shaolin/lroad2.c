// Room: /d/shaolin/lroad2.c

inherit ROOM;

void create()
{
	set("short", "前院过道");
	set("long", @LONG
这里是少林寺的前院过道，两边树林丛荫，时而可以听到几
声鸟鸣，你不由赞叹，少林寺果然是一个修行的清幽之地。西边
没多远是一做小假山，估计是善男信女们起修的。从这里向北是
西广场，向南是过道，向西是一个练武场。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lroad1",
  "west" : __DIR__"lwc_w",
  "north" : __DIR__"w_square",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
