// /d/huashan/buguigu.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIR"不归谷"NOR);
        set("long", @LONG
这里是一个奇怪的山谷，整个山谷云雾缭绕，大概就是华山
弟子常常说起的“不归谷”。从这里向东是乱石路，北边是陡峭
的山路。
LONG
        );
        
        set("exits", ([
                "eastup" : __DIR__"sroad2",
                "northdown" : __DIR__"bsroad1",
        ]));

        set("outdoors","huashan");

        setup();
}


