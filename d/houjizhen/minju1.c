// minju1.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
这是一家用木头搭的房屋，家徒四壁，屋角的米缸是空的，厨房内
的水缸也是空的。几个缺胳膊少腿的桌椅靠墙立着。看来主人已经把所
有能值钱的东西全都变卖了。
LONG
        );

        set("exits", ([
                "north" : __DIR__"shilu5",
        ]));

	set("objects", ([
		"/d/gaibang/npc/xie" : 1,
	]));

        setup();
        replace_program(ROOM);
}
