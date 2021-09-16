// /d/hangzhou/flowershop.c

inherit ROOM;

void create()
{
        set("short", "花店");
        set("long", @LONG
走进大门，你发现你已经置身于花的海洋，各式各样的花朵
竞相绽放，一个明眸皓齿的女孩俏立在花丛中，满屋的春色也掩
盖不了她的微笑。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"changanw3",
]));

	set("objects",([
	__DIR__"npc/hua_boss" : 1,
]));
        setup();
        replace_program(ROOM);
}

