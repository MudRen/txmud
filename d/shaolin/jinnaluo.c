// Room: /d/shaolin/jinnaluo.c

inherit ROOM;

void create()
{
	set("short", "紧那罗殿");
	set("long", @LONG
这里是少林寺的紧那罗殿，紧那罗本是梵文中疑人、人非人、
疑神之意，是八部众中奏法乐之神。正中是大神紧那罗，两边供
奉着其它七部天的神像，好不威严。从这里向西是东广场，向东
走是少林寺的钟楼。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhonglou1",
  "west" : __DIR__"e_square",
]));

	set("objects",([
	__DIR__"npc/kongxing" : 1,
]));

	setup();
	replace_program(ROOM);
}
