//gate.c 德木寺正门。
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"德木寺"NOR);
        set("long", @LONG
这就是藏传格鲁教派的著名寺庙----德木寺。格鲁派也就是
所谓的黄教，宁玛派则是红教，都是密宗的分支。密宗是天竺来
的莲花生大师来时所传，莲花生打败了原来的苯教才得以在此地
传教。据说在偏远地区仍有苯教流传。这里是德木寺的正门，有
两个僧兵在门前看护。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "north":__DIR__"temple1",
        "south":"/wiz/saying/work/linzhi/lz_cross",
]));
        set("objects",([
        __DIR__"npc/lama" : 2,
]));
        setup();
}
