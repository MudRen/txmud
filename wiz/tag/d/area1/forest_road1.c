///////////////////////////////////////////////////
//【林间小路】 [/d/path3/k_h22]
//新的区域area1
//forest_road1.c

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
        "west"        :  "/d/path3/k_h22",
        "east"        :  __DIR__"forest_road2",
        "north"       :  __DIR__"forest_road1",
        "south"       :  __DIR__"forest_road1",
        ]));
        set("outdoors", "area1");
        
        setup();

        replace_program(ROOM);
}
///////////////////////////////////////////////////
