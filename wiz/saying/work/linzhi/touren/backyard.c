//backyard.c 后院。
inherit ROOM;
void create()
{
        set("short","后院");
        set("long", @LONG
这里是头人府的后院，可能是因为是家属住的地方，这里的
布置要柔和的多了，不像前面那样剑拔弩张。东边是查查头人的
居室，西边是查查练武的地方。
LONG
        );
        set("exits", ([
        "east":__DIR__"chacha_room",
        "west":__DIR__"chacha_room2",
        "north":__DIR__"backyard2",
        "out":__DIR__"road2",
]));
        setup();
}
