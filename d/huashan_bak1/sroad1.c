// /d/huashan/sroad1.c

inherit ROOM;

void create()
{
        set("short", "乱石路");
        set("long", @LONG
这里就是铁矿场北面的崎岖小路。这里到处都是石头，走起
来非常困难，而前方却还是一望无际，似乎没有尽头，让人没有
继续走下去的欲望。从这里向南是铁矿场，北面仍然是乱石路。
LONG
        );
        
        set("exits", ([
                "north" : __DIR__"sroad2",
                "south" : "/d/huashan/tieku",
                //"south" : __DIR__"tieku",
        ]));

        set("outdoors","huashan");

        setup();
}

