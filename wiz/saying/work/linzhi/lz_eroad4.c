//lz_eroad4.c 林芝村东口
inherit ROOM;
void create()
{
        set("short","村东山路");
        set("long", @LONG
走过原始森林，前方是一个小村庄，看上去跟中原的建筑风
格迥异，应该就是林芝了。这里所住的大多是藏族人，不过跟中
原交流很少，只有很少的人为了避难从中原逃到这里。
LONG
        );
        set("exits", ([
        "east":__DIR__"lz_eroad5",
        "west":__DIR__"lz_eroad3",
        "south":__DIR__"lz_guard",
]));
        set("objects",([
        __DIR__"npc/guardian":4,
]));
        setup();
}
