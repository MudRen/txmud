// Room: /d/shaolin/gulou3.c

inherit ROOM;

void create()
{
	set("short", "鼓楼三层");
	set("long", @LONG
这里是少林寺的鼓楼三层，随着向高光线也渐渐明亮起来。
你可从楼旁的小窗口中清楚的看到少林寺的全貌，也可以借着昏
暗的光看清鼓楼墙壁上绘着的各种古老的壁画。从这里延楼梯向
向下是鼓楼二层，向上是鼓楼的顶楼。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"gulou2",
  "up" : __DIR__"gulou4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
