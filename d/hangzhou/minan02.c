// /d/hangzhou/minan02.c

inherit ROOM;

void create()
{
        set("short", "民安北街");
        set("long", @LONG
行人和你擦肩而过，一些小贩在沿街叫卖。一个老妇急步向
东面走去，像是到杂货店里去买什么东西。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"cross",
            "north"  : __DIR__"minan01",
            "east"   : __DIR__"shop",
]));


        set("objects",([
        __DIR__"npc/beggar" : 1,
        NPC_DIR"xunpu" : 1,
]));

        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

