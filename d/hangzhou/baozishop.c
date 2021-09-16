// /d/hangzhou/baozishop.c

inherit ROOM;

void create()
{
        set("short", "包子铺");
        set("long", @LONG
一进店门，一阵阵的香气混合了醋味迎面扑来，味道虽然比
不上西子湖畔有名的知味观，但对于饥肠碌碌的行人来说，也是
无法抗拒的，店小二正在跑来跑去的招呼客人，看来生意不错。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"changane1",
]));

	set("objects",([
	__DIR__"npc/baozi_huoji" : 1,
]));

        setup();
        replace_program(ROOM);
}

