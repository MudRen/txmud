// dt_fenduo_3.c

inherit ROOM;

void create()
{
        set("short", "天井");
        set("long", @LONG
空空荡荡的天井，没有什么东西能吸引你的注意，除了几只
在地上蹦来跳去的小鸟。回头看看房子，似乎围墙都比房子要牢
固得多。这里总算是没有屋里的那股怪味了，你不由得深深吸了
口气。
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
                "west" : __DIR__"dt_fenduo",
        ]));

        set("objects",([
        ]));

        set("outdoors", "datong");

        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me = this_player();
        if( !arg || arg != "围墙") return 0;
        if ( arg =="围墙")
        {
                message_vision("$N双手一撑，翻过了墙去。\n", me);
                me->move(__DIR__"dt_fenduo_4");
                message("vision", me->name() + "从另一边翻墙跳了过来。\n", environment(me), me);
        }
        return 1;
}
