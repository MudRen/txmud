// /d/hangzhou/minan05.c

inherit ROOM;

void create()
{
        set("short", "民安南街");
        set("long", @LONG
民安街贯穿杭州府南北，算得上是杭州府最繁华的街市了，
赌场，妓院之类的风月场所多半建在这条街上，虽然名为民安，
实际上却是城里最不安生的地方。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"cross1",
            "north"  : __DIR__"minan04",
            "east"   : __DIR__"dangpu",
            "west"   : __DIR__"zhubaoshop",
]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

