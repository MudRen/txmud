// /d/huashan/bsroad2.c

//#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里是一片地势陡峭的山路，也许是有雾的关系，你勉强能
看清前面的路。这里的路面很湿滑，加之地势陡峭，走在路面好
象有坠入山谷的危险，还是快些赶路要紧。从这里向南是陡峭的
山路，北边是悬崖。
LONG
        );
        
        set("exits", ([
                "southdown" : __DIR__"bsroad1",
                "northup" : __DIR__"bxuanya",
        ]));

        set("outdoors","huashan");

        setup();
}

