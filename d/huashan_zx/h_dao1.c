// h_dao1.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "门前小路");
        set("long", @LONG
你走在紫霞宫后门前的一条小路上, 路两旁开着一些不知名
的花卉, 向南可以不远处可以望见一扇红漆大门。东边就是紫霞
宫的马厩，你要是办什么急事可以骑马去。
LONG
);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"houmen",
  "northup" : "/d/huashan/qitu3",
]));

        set("outdoors", "huashan_zx");

	setup();
        create_door("south", "朱漆大门", "north", DOOR_CLOSED);
}
