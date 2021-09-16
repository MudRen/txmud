// Room: houmen.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short","紫霞宫后门");
	set("long",@LONG
这里比起紫霞宫的前门来要简单的多，就是两扇镶着铜钉的
对开朱漆大门。从这里出去可以能向莲花峰，当然也可以下山不
过要多绕些道罢了。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                "north" : __DIR__"h_dao1",
                "south" : __DIR__"guodaoe10",
        ]));

        set("outdoors", "huashan_zx");

        set("objects", ([
		//__DIR__"npc/lm_guard": 2 
        ]) );

        setup();
	create_door("north", "朱漆大门", "south", DOOR_CLOSED);
}
