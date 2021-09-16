// dt_fenduo_2.c

inherit ROOM;

void create()
{
        set("short", "厢房");
        set("long", @LONG
你一进这间房间就不禁咕哝：这算是什么厢房啊？整个房间
都马上要塌下来了，甚至房间的一角已然是破开，直接就是露天
的了。这里几乎什么家具也没有，只有张破烂不堪的床。
LONG
);

        set("no_clean_up", 1);
        set("sleep_room", 1);
        set("exits", ([
                "south" : __DIR__"dt_fenduo",
        ]));

        set("item_desc", ([
                "床" : "这张看起来破旧的床似乎倒还结实得很。\n",
        ]));

        setup();
}
