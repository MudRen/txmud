//tower_e.c 头人府哨塔。
inherit ROOM;
void create()
{
        set("short","哨塔");
        set("long", @LONG
这里是头人府的哨塔。哨塔完全是头人威严的体现，其实查
查头人并不像前任头人一样喜欢作威作福，只是在这个位子上呆
久了，难免有点贵族习气。
LONG
        );
        set("exits", ([
        "west":__DIR__"gate",
        "up":__DIR__"uptower_e",
]));
        setup();
}
