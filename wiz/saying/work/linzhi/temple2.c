//temple2.c 错宗工巴寺后殿。
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "后殿");
        set("long",
"这里是错宗工巴寺的后殿，这里非常昏暗，而且空无一物，\n"
"只有对面的墙壁上有三行比较显眼的字：\n"
HIR"\t\t大\t自\t心\n"
HIR"\t\t悲\t性\t体\n"
HIR"\t\t周\t元\t本\n"
HIR"\t\t遍\t成\t净\n"NOR
        );
        set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"temple1",
]));
        set("objects",([
        __DIR__"npc/old_lama" : 1,
]));
        setup();
}
