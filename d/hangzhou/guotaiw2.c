// /d/hangzhou/guotaiw2.c

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
            "north"  : __DIR__"zhifu",
            "east"   : __DIR__"guotaiw1",
            "west"   : __DIR__"guotaiw3",
]));
        set("outdoors", "hangzhou");
        set("cannot_build_home", 1);

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 2,
]));

        setup();
        replace_program(ROOM);
}

