//bank_under.c 钱庄秘道入口。
inherit ROOM;
void create()
{
        set("short","地道入口");
        set("long", @LONG
这里是一条阴暗潮湿的地道，两旁的墙壁上挂着点点水珠，
地上布满了脚印，似乎经常有人从这里走过。
LONG
        );
        set("exits", ([
        "west":__DIR__"bank_d/entry",
]));
        setup();
}
