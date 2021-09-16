// Room: /d/mafeng/up8.c

inherit ROOM;

void create()
{
	set("short", "上山小路");
	set("long", @LONG
这是一条青石铺就的上山小路，路上的石头已经被磨成了向
下的斜坡，看样子年代已经非常久远了。回头向下看是一片浓密
的树林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"up9",
  "southdown" : __DIR__"up7",
]));

	set("outdoors", "mafeng");
	setup();
	replace_program(ROOM);
}

#include "kill.h";