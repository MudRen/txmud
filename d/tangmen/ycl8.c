// Room: /d/tangmen/ycl8.c

inherit ROOM;

void create()
{
	set("short", "羊肠小路");
	set("long", @LONG
这是一条蜿蜒曲折的小路，右面是一小片低矮的树林，左面
是陡峭的山壁。地上满是乱石子，有的还很尖利，看样子这里很
少有人来。正前方是一堆粗大的原木挡住了去路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ycl7",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
