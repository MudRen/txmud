// Room: /d/shaolin/zhonglou2.c

inherit ROOM;

void create()
{
	set("short", "钟楼二层");
	set("long", @LONG
这里是少林寺的钟楼二层，只有专门负责撞钟的僧人才可以
来这里，因为经常的打扫，这里很干净。墙壁上绘着美丽的飞天
壁画。从这里向上和向下是钟楼和三层和一层。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"zhonglou1",
  "up" : __DIR__"zhonglou3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
