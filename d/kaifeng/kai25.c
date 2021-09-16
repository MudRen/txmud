// Room: /u/w/wangs/b/kai25.c

inherit ROOM;

void create()
{
	set("short", "背阴小巷");
	set("long", @LONG
这里是一条深深的小巷，两边是居民家中拉起的高高的青砖
院墙。在青黑色的院墙上间或开着几扇紧闭的大门。这里终年见
不到阳光，所以给人一种阴阴森森的感觉。南面一扇朱红色的大
门却是敞开的，门边挂着一面招牌，上面写着“海鲜”两个大字。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"kai27",
  "south" : __DIR__"kai26",
  "west" : __DIR__"kai23",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
