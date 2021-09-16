// Room: /d/mafeng/up1.c

inherit ROOM;

void create()
{
	set("short", "上山小路");
	set("long", @LONG
这是一条青石铺就的上山小路，路上的石头已经被磨成了向
下的斜坡，看样子年代已经非常久远了。
LONG
	);
	set("exits", ([
  "northeast" : __DIR__"up2",
  "southwest" : "/d/path3/cross6",
]));

	set("outdoors", "mafeng");
	setup();
	replace_program(ROOM);
}

#include "kill.h";