// Room: /d/hangzhou/zfzf.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是杭州知府处理日常事务的地方，正中间有一张檀木书
桌，上面摆的却是一把酒壶，靠墙的地方有一个大书架，上面摆
满了各种书籍，走近却发现上面覆盖了厚厚的尘土，看来好久没
有人碰过了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zfpath7",
]));

	setup();
	replace_program(ROOM);
}
