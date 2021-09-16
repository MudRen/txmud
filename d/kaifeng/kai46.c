// Room: /u/w/wangs/b/kai46.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里堆满了几个大草墩，还有各种马饲料、乘具，墙边地方
靠着几只大扫把。几个伙计正在调拌饲料，据说川马和滇马吃的
饲料都是不同的从这里可以看到三个马厩里马头攒动，马嘶之声
不绝于耳，快去挑一匹好马代步吧。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai45",
]));
        set("objects",([
        __DIR__"npc/maboss":1,
        __DIR__"npc/huoji":2,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
