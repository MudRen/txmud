///////////////////////////////////////////////////
//新的区域area1
//forest_road2.c

inherit ROOM;

void create()
{
        set("short", "密林之中");
        set("long", @LONG
你穿行在浓密的树林中，四周围密密麻麻都是树，让
你难以分辨身在何方。东南西北似乎都是一个样子，让你
难以决定要往哪边走才好。时不时你还能听到林中传来的
奇怪的声音。
LONG
        );
        set("exits", ([
        "west"        :  __DIR__"forest_road1",
        "east"        :  __DIR__"forest_road1",
        "north"       :  __DIR__"forest_road3",
        "south"       :  __DIR__"forest_road1",
        ]));
        set("outdoors", "area1");
        
        setup();

        replace_program(ROOM);
}
///////////////////////////////////////////////////
