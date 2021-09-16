// Room: /u/w/wangs/b/kai23.c

inherit ROOM;

void create()
{
	set("short", "背阴小巷");
	set("long", @LONG
这里是一条深深的小巷，两边是居民家中拉起的高高的青砖
院墙。在青黑色的院墙上间或开着几扇紧闭的大门。这里终年见
不到阳光，所以给人一种阴阴森森的感觉。南边是一家木匠铺。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai24",
  "north" : __DIR__"kai190",
  "west" : __DIR__"kai21",
  "east" : __DIR__"kai25",
]));
	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
