//temple1.c 错宗工巴寺正殿。
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"错宗工巴寺"NOR);
        set("long", @LONG
这就是藏传宁玛教派的著名寺庙----错宗工巴寺，在这个小
岛上，倒是有如世外仙境一般。你现在所在的地方是正殿，迎面
一个大匾额上写着『错宗工巴寺』五个大字，世尊佛的金身塑像
在缭绕的香烟中若隐若现。几个红衣喇嘛坐在蒲团上低声梵唱，
一霎那间，你仿佛也脱离了这个烦恼无边的尘世。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"lake_w",
        "west":__DIR__"temple2",
        "north":__DIR__"temple3",
        "south":__DIR__"temple4",
]));
        set("objects",([
        __DIR__"npc/red_lama" : 4,
]));
        setup();
}
