//lz_sroad4.c 林芝村南街
inherit ROOM;

void create()
{
        set("short","林芝南街");
        set("long", @LONG
这里就是林芝村的南街。林芝，在藏语中是『太阳宝座』的
意思，在西藏地区，林芝确实是靠东的部分。因为群山环绕，森
林繁茂，大江经过，所以景色十分迷人。东面是一处哨所，西面
则是通向拉萨的一条大路。
LONG
        );

        set("exits", ([
        "north":__DIR__"lz_sroad3",
        "east":__DIR__"lz_guard2",
//        "west":__DIR__"tibet",
]));
        set("objects",([
        __DIR__"npc/guardian":2,
]));
        setup();
}
