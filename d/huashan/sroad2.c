// /d/huashan/sroad2.c

inherit ROOM;

void create()
{
        set("short", "乱石路");
        set("long", @LONG
这里是一个荒凉的崎岖小路。这里到处都是石头，走起来非
常困难，前方隐约能看见出路。从这里向南是乱石路，东北是一
个小树林，西边是不归谷。
LONG
        );
        
        set("exits", ([
                "northeast" : __DIR__"sm_wood",
                "westdown" : __DIR__"buguigu",
                "south" : __DIR__"sroad1",
        ]));

        set("outdoors","huashan");

        setup();
}

