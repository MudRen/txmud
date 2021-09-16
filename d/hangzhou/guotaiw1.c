// /d/hangzhou/guotaiw1.c

inherit ROOM;

void create()
{
        set("short", "国泰路");
        set("long", @LONG
这里是杭州最宽阔的一条街，杭州府的知府衙门就座落在这
条街上，因此这条路上的行人也比较少，另外，名震大江南北的
震远镖局也座落在这条街上。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"guardgroup",
            "east"   : __DIR__"cross1",
            "west"   : __DIR__"guotaiw2",
]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

