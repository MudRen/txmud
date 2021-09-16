// dt_fenduo_4.c

inherit ROOM;

void create()
{
        set("short", "空地");
        set("long", @LONG
这里就是破旧大院后面的空地，杂草丛生，没过了你的脚踝。
想想繁华的大同府里竟然还有这么大一块空地，你不由得暗呼奇
怪。一个乞丐打扮的人在不远处耍着棍子。
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
        ]));

        set("objects",([
                __DIR__"npc/dt_duozhu" : 1,
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
                me->move(__DIR__"dt_fenduo_3");
                message("vision", me->name() + "从另一边翻墙跳了过来。\n", environment(me), me);
        }
        return 1;
}
