//wood_room.c 头人府柴房。
inherit ROOM;
void create()
{
        set("short","柴房");
        set("long", @LONG
这里是头人府的柴房，主要是供给厨房燃料用的。
LONG
        );
        set("exits", ([
        "east":__DIR__"garden",
]));
        set("objects",([
        __DIR__"npc/servant_gaci":1,
]));
        setup();
}
