// /d/huashan/sm_wood.c

inherit ROOM;

void create()
{
        set("short", "小树林");
        set("long", @LONG
这里是一个茂密的小树林。这里散发着怪异的味道，树林看
起来很阴森，让你直起鸡皮疙瘩。树林里偶尔还能听见几声奇怪
的鸟叫声，那声音好象从来都没有听过，你感觉有些心慌。从这
里向南是乱石路，东北是一个小树林，西边是不归谷。
LONG
        );
        
        set("exits", ([
                "southwest" : __DIR__"sroad2",
                "east" : __DIR__"jindi_gate",
        ]));

        set("outdoors","huashan");

        setup();
}


