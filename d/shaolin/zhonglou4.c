// Room: /d/shaolin/zhonglou4.c

inherit ROOM;

void create()
{
	set("short", "钟楼四层");
	set("long", @LONG
这里是少林寺的钟楼顶楼四层，一进来最醒目是那口巨钟，
足有几丈高的大铜钟上，刻着金刚般若波罗密经，光是这口钟就
堪称是佛宝了。你试着撞了下那钟，宏然清亮。从这里向下是钟
楼三层。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"zhonglou3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
