// Room: /d/hangzhou/sudi3.c

inherit ROOM;

void create()
{
	set("short", "苏堤");
	set("long", @LONG
这里苏杭最有名的景致之一--苏堤。你步伐轻快的走在堤上
感受着周围草长莺飞的风景，三三两两的游人和你擦身而过，每个
人脸上都洋溢着喜悦的表情。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"rockroad1",
]));

	setup();
	replace_program(ROOM);
}
