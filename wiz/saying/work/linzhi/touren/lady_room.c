//lady_room.c 夫人住房。
inherit ROOM;
void create()
{
        set("short","夫人居室");
        set("long", @LONG
这里是头人夫人的居室。跟头人的房间一样，这里也只有几
样必需的家具，床也只是加了一个粉红的纱帐，看起来夫人也是
一个平易近人的长者。
LONG
        );
        set("exits", ([
        "west":__DIR__"backyard2",
]));
        set("objects",([
        __DIR__"npc/lady":1,
]));
        setup();
}
