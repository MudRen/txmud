// /d/hangzhou/tangyuanshop.c

inherit ROOM;

void create()
{
        set("short", "汤圆铺子");
        set("long", @LONG
所谓铺子，不过是路边支着的一个芦席篷子，旁边的一口大
铁锅咕嘟咕嘟的沸腾着，阵阵的香气随风飘散。几个旅客模样的
人座在篷子下吃得正香。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"changane3",
]));
        setup();
        replace_program(ROOM);
}

