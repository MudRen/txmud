// Room: /d/shaolin/chaifang.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
这里是少林寺的柴房，一间普通的小草屋中堆满了一些柴草。
不远处有一个大木墩，几个烧火僧正忙着劈柴往不远处斋堂，从
这里向东是西跨院。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"houshan1",
  "east" : __DIR__"w_court",
]));

	set("objects",([
	__DIR__"npc/heshang" : 1,
]));

	setup();
        create_door("northwest", "柴门", "southeast", DOOR_CLOSED);
	replace_program(ROOM);
}
