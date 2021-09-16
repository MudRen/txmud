//lz_eroad2.c 林芝村东街
inherit ROOM;

void create()
{
        set("short","林芝东街");
        set("long", @LONG
这里就是林芝村的东街。林芝，在藏语中是『太阳宝座』的
意思，在西藏地区，林芝确实是靠东的部分。因为群山环绕，森
林繁茂，大江经过，所以景色十分迷人。南面是一家当铺，北面
则是一家民居。
LONG
        );

        set("exits", ([
        "east":__DIR__"lz_eroad3",
        "west":__DIR__"lz_eroad1",
        "north":__DIR__"house1",
        "south":__DIR__"dangpu",
]));
        setup();
}
