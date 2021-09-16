//lz_sroad1.c 林芝村南街
inherit ROOM;

void create()
{
        set("short","林芝南街");
        set("long", @LONG
这里就是林芝村的南街。林芝，在藏语中是『太阳宝座』的
意思，在西藏地区，林芝确实是靠东的部分。因为群山环绕，森
林繁茂，大江经过，所以景色十分迷人。东面是一家兵器铺，西
面则是一家民居。
LONG
        );

        set("exits", ([
        "east":__DIR__"weapony",
        "west":__DIR__"house2",
        "north":__DIR__"lz_cross",
        "south":__DIR__"lz_sroad2",
]));
        setup();
}
