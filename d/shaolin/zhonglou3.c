// Room: /d/shaolin/zhonglou3.c

inherit ROOM;

void create()
{
	set("short", "钟楼三层");
	set("long", @LONG
这里是少林寺的钟楼三层，从楼边的小窗向外看，你可以鸟
瞰少林寺的全貌。楼的两边有一排排的壁灯，常有人往里灌香油，
常年也不灭的。从这里向上是钟楼顶楼，向下是钟楼二层。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"zhonglou2",
  "up" : __DIR__"zhonglou4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
