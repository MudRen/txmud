//backyard2.c 后院。
inherit ROOM;
void create()
{
        set("short","后院");
        set("long", @LONG
这里是头人府的后院，可能是因为是家属住的地方，这里的
布置要柔和的多了，不像前面那样剑拔弩张。东边是头人夫人的
居室，西边是贴身服侍夫人的丫鬟住的地方。
LONG
        );
        set("exits", ([
        "east":__DIR__"lady_room",
        "west":__DIR__"servant_room3",
        "north":__DIR__"miss_room",
        "south":__DIR__"backyard",
]));
        setup();
}
