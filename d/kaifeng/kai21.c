// Room: /u/w/wangs/b/kai21.c

inherit ROOM;

void create()
{
	set("short", "背阴小巷");
	set("long", @LONG
这里是一条深深的小巷，两边是居民家中拉起的高高的青砖
院墙。在青黑色的院墙上间或开着几扇紧闭的大门。这里终年见
不到阳光，所以给人一种阴阴森森的感觉。北面传来人声，你伸
头一看，原来这里是一个小小的茶馆。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"kai22",
  "west" : __DIR__"kai19",
  "east" : __DIR__"kai23",
]));

        set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 3,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
