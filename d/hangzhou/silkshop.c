// /d/hangzhou/silkshop.c

inherit ROOM;

void create()
{
        set("short", "福安绸缎庄");
        set("long", @LONG
这里是杭州城里最大的绸缎庄，杭州丝绸天下闻名，杭州城
的富户多从这里买货，慕名而来的外地客商更是人如潮涌，怪不
得掌柜的常常喜笑颜开。
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"changanw1",
]));
        setup();
        replace_program(ROOM);
}

