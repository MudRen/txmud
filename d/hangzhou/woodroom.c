// /d/hangzhou/woodroom.c

inherit ROOM;

void create()
{
        set("short", "木匠铺子");
        set("long", @LONG
满屋的灰尘当中，木匠正手拿斧凿，加工着什么东西，看见
你进来连忙直起身招呼：客官，您是要打造家具，还是做个棺材
玩玩？
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"changane3",
]));
        setup();
        replace_program(ROOM);
}

