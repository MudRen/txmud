//lz_cross.c 林芝村路口
inherit ROOM;

void create()
{
        set("short","十字路口");
        set("long", @LONG
这里就是林芝村的路口。林芝，在藏语中是『太阳宝座』的
意思，在西藏地区，林芝确实是靠东的部分。因为群山环绕，森
林繁茂，大江经过，所以景色十分迷人。南面是林芝的南街，北
面则是一家寺庙。
LONG
        );

        set("exits", ([
        "east":__DIR__"lz_eroad1",
        "west":__DIR__"lz_wroad1",
        "north":__DIR__"temple/gate",
        "south":__DIR__"lz_sroad1",
]));
        set("objects",([
        __DIR__"npc/lama":1,
        __DIR__"npc/hunter":2,
]));
        setup();
}
