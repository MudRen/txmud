// zoulang6.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "东廊");
        set("long", @LONG
这是一条走廊，廊顶描绘着江南秀美的风景。每两根翠绿色的柱子间相隔
也就两三尺的距离，朱红色的琉璃瓦，嫩黄色的地砖。在走廊里面，丫鬟、奴
仆们走来走去，都忙着自己的事情，不敢有一点怠慢。
LONG
        );

        set("exits", ([
               "west" : __DIR__"donglang1",
               "east" : __DIR__"shilu5",
               "south" :__DIR__"bingqiku",		  
        ]));

        set("objects", ([
                __DIR__"npc/yahuan1" : 2,
        ]));

        setup();
	replace_program(ROOM);
}
