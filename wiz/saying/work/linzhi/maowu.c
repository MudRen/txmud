//maowu.c 第五大爷住的地方。
inherit ROOM;
void create()
{
        set("short","小茅屋");
        set("long", @LONG
这是一间破旧的小茅屋，天光从支离破碎的屋顶和墙壁间
透过来。借着微弱的光线你可以看到屋里的东西堆放得凌乱不
堪，不过墙壁上挂着几头野鸡野兔似乎还很新鲜。
LONG
        );
        set("exits", ([
        "west":__DIR__"lz_eroad5",
]));
        set("objects",([
        __DIR__"npc/oldman":1,
]));
        setup();
}
