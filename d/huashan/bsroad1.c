// /d/huashan/bsroad1.c

//#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里是一片地势陡峭的山路，也许是有雾的关系，你勉强能
看清前面的路。这里的路面很湿滑，加之地势陡峭，走在路面好
象有坠入山谷的危险，还是快些赶路要紧。从这里向南是不归谷，
北边是陡峭的山路。
LONG
        );
        
        set("exits", ([
                "southup" : __DIR__"buguigu",
                "northup" : __DIR__"bsroad2",
        ]));

        set("outdoors","huashan");

        setup();
}


