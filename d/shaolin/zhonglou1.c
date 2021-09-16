// Room: /d/shaolin/zhonglou1.c

inherit ROOM;

void create()
{
	set("short", "钟楼一层");
	set("long", @LONG
这里是少林寺的钟楼一层，每天不论是早课晚课，还是入寝
开饭，都要在这里敲出洪亮的钟声。尤其每逢佛教的大典，象是
盂兰盆会，佛诞日这样的日子，这里的钟声几乎不绝。从这里向
西是紧那罗殿，顺楼梯向上是钟楼二楼。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"zhonglou2",
  "west" : __DIR__"jinnaluo",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
