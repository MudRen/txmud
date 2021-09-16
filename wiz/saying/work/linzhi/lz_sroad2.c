//lz_sroad2.c 林芝村南街
inherit ROOM;

void create()
{
        set("short","林芝南街");
        set("long", @LONG
这里就是林芝村的南街。林芝，在藏语中是『太阳宝座』的
意思，在西藏地区，林芝确实是靠东的部分。因为群山环绕，森
林繁茂，大江经过，所以景色十分迷人。东面是一家民居，西面
则是一家药店。
LONG
        );

        set("exits", ([
        "east":__DIR__"house3",
        "west":__DIR__"yaodian",
        "north":__DIR__"lz_sroad1",
        "south":__DIR__"lz_sroad3",
]));
        setup();
}
