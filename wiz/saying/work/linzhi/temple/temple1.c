//temple1.c 德木寺广场。
inherit ROOM;
void create()
{
        set("short", "广场");
        set("long", @LONG
这里是德木寺的广场。说是广场，倒不如说是草地更恰当一
点。草地上养着几只说不出名字的羊，一派自在悠然的景象。前
方隐隐有一座大殿，东面是塔林，西面是练武场。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"t_right1/entry",
        "west":__DIR__"t_left1",
        "north":__DIR__"temple2",
        "south":__DIR__"gate",
]));
        setup();
}
