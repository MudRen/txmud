//cook_room.c 头人府厨房。
inherit ROOM;
void create()
{
        set("short","厨房");
        set("long", @LONG
这里是头人府的厨房，负责全府的伙食。旁边还有一个小隔
间，是专门给老爷太太们做饭的地方。虽然工作量很大，不过这
里的师父们还是有条有理的忙着，而且厨房也很整洁。
LONG
        );
        set("exits", ([
        "north":__DIR__"garden",
]));
        set("objects",([
        __DIR__"npc/cook":1,
]));
        setup();
}
