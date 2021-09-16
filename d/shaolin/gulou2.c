// Room: /d/shaolin/gulou2.c

inherit ROOM;

void create()
{
	set("short", "鼓楼二层");
	set("long", @LONG
这里是少林寺的鼓楼二层，虽然常有人打扫，可是因为年代
的古远，显得很是荒凉。光线很是黑暗，即使是白天也必须有灯
才可以看得见路。从这里向上是三层，从楼梯向下是一层。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"gulou1",
  "up" : __DIR__"gulou3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
