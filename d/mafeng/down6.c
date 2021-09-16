// Room: /d/mafeng/down6.c

inherit ROOM;

void create()
{
	set("short", "地下过道");
	set("long", @LONG
这里是一条宽敞的地下过道，地下铺着青砖的条石，四周的
墙壁铲得非常的平整，看样子建造这里花了不少心血，两旁的墙
壁上插着胳膊粗的火把照亮了整条过道。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"down7",
  "east" : __DIR__"down5",
]));

	setup();
}

void reset() { }

#include "kill.h";