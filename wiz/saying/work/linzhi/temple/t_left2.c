//t_left2.c 德木寺休息室。
inherit ROOM;
void create()
{
        set("short", "休息室");
        set("long", @LONG
这里是德木寺的休息室，主要是喇嘛们休息的地方，游客如
果累了也可以在这里歇一会儿。这里有几张空床，上面的被褥都
很整齐。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"temple2",
]));
        set("sleep_room",1);
        setup();
}
