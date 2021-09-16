//yaodian.c 林芝村的药店。
inherit ROOM;
void create()
{
        set("short", "小医馆");
        set("long", @LONG
这里是林芝村的小医馆，因为村里不少人会功夫，而且从
事打猎，经常有些小伤小病需要来拿点药看看病。这里的医生
治病方法同普通中医有区别，而且听说大多数都会用蛊的，你
心里掂量了一下，脚步开始往门口挪。
LONG
);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"lz_sroad2",
]));

        set("objects",([
        __DIR__"npc/doctor":1,
        __DIR__"npc/xiaohuoji":1,
]));
        setup();
        replace_program(ROOM);
}
