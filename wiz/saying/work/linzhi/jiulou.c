//jiulou.c  林芝村的酒楼
inherit ROOM;
inherit SHOW_MSG;
void create()
{
        set("short", "香格里拉林芝分号");
        set("long", @LONG
这里是林芝村的酒楼，是有名的香格里拉大酒店的分号。据
说掌厨的师傅都是从布达拉宫里服侍活佛退休之后来的，手艺相
当的好。现在正是日里最热闹的时候，楼下大厅楼上雅座都坐满
了人，无论是富人平民都能在这里享受到很好的服务，只是忙坏
了女招待们。
LONG
);
        set("night_long", @LONG
这里是林芝村的酒楼，是有名的香格里拉大酒店的分号。现
在华灯初上，酒楼已经打烊了。不过楼上的雅座里似乎还有人，
只是灯光昏暗，看不清是谁。酒楼的女招待睡眼惺忪的过来招呼
你，不过你顶多是在这里休息一会儿，不可能有吃喝的。
LONG
);
        set("exits", ([
        "north":__DIR__"lz_eroad1",
        "up":__DIR__"jiulou2",
        "south":__DIR__"cookroom",
]));
        set_master("xiao jie");
        set(SAFE_ENV, 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("objects",([
        __DIR__"npc/waitress":1,
]));
        setup();
}
