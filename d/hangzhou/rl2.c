// /d/hangzhou/rl2.c

inherit ROOM;

void create()
{
        set("short", "苏来客栈二楼");
        set("long", @LONG
走上楼梯，迎面是一个长长的过道，一边是栏杆，可以看到
一层大厅，另一边是一排宽敞明亮的客房。
LONG
        );
        set("exits", ([ 
            "down"  : __DIR__"restaurant",
            "up"  : __DIR__"rl3",
]));
        setup();
        replace_program(ROOM);
}

