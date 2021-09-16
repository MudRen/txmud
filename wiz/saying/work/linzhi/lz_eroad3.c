//lz_eroad3.c 林芝村东街
inherit ROOM;

void create()
{
        set("short","林芝东街");
        set("long", @LONG
这里就是林芝村的东街。林芝，在藏语中是『太阳宝座』的
意思，在西藏地区，林芝确实是靠东的部分。因为群山环绕，森
林繁茂，大江经过，所以景色十分迷人。南面是一家铁匠铺，北
面则是一个杂货铺。
LONG
        );

        set("exits", ([
        "east":__DIR__"lz_eroad4",
        "west":__DIR__"lz_eroad2",
        "north":__DIR__"shop",
        "south":__DIR__"smith_room",
]));
        set("objects",([
        __DIR__"npc/boy":1,
        __DIR__"npc/girl":1,
]));
        setup();
}
