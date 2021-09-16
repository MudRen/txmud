// Room: /d/mafeng/out1.c

inherit ROOM;

void create()
{
	set("short", "狭窄过道");
	set("long", @LONG
这是一条狭窄的地下过道，边上的墙上插着一只火把，昏暗
的火光照着过道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"out2",
]));

	setup();
	replace_program(ROOM);
}

#include "kill.h";