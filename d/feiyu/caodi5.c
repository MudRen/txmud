#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"caodi4",
  "north" : __DIR__"ting",
]));

	setup();
}

