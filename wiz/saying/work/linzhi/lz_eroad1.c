//lz_eroad1.c 林芝村东街
inherit ROOM;

void create()
{
        set("short","林芝东街");
        set("long", @LONG
这里就是林芝村的东街。林芝，在藏语中是『太阳宝座』的
意思，在西藏地区，林芝确实是靠东的部分。因为群山环绕，森
林繁茂，大江经过，所以景色十分迷人。南面是一家酒楼，北面
则是一个钱庄。
LONG
        );

        set("exits", ([
        "east":__DIR__"lz_eroad2",
        "west":__DIR__"lz_cross",
        "south":__DIR__"jiulou",
        "north":__DIR__"bank",
]));
        setup();
}
