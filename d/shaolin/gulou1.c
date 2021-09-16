// Room: /d/shaolin/gulou1.c

inherit ROOM;

void create()
{
	set("short", "鼓楼一层");
	set("long", @LONG
这里是鼓楼的一层，少林寺只有在遇到强敌时，才会敲鼓示
警，所以说这里无事的闲人是不许来的。鼓楼显然已经很古旧了，
墙壁上的粉已经剥落了不少，露出了里面的青砖。从这里向东是
六祖庙，从小楼梯向上是二层。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"6zumiao",
  "up" : __DIR__"gulou2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
