// Room: /d/shaolin/qhs2.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "后山");
	set("long", @LONG
这里是少室山的后山，东北面是一处宏大的寺庙，那就是名
满武林的少林寺了，西面是一条蜿蜒的小径通向远方。路旁立着
一块石碑(bei)，上面写这几个鲜红的大字。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"qhs1",
  "west" : __DIR__"qsl/entry",
]));

	set("item_desc",([
	"石碑" : HIR"\n前方有蛇伤人！！\n\n"NOR,
	"bei" : HIR"\n前方有蛇伤人！！\n\n"NOR,
]));
	setup();
	replace_program(ROOM);
}
