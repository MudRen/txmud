//secrety.c 通往牢房。
#include <room.h>
inherit ROOM;
void create()
{
        set("short","密室");
        set("long", @LONG
这里是一间小小的密室，墙壁上挂着点点水珠，非常的潮
湿，这里简直不是人住的地方。
LONG
        );
        set("exits", ([
        "west":__DIR__"main",
        "down":__DIR__"jail/entry",
]));
        setup();
        create_door("west", "木门", "east", DOOR_CLOSED,LOCKED,__DIR__"obj/jail_key");
}
