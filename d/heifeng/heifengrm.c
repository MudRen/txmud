// /d/heifeng/heifengrm.c

inherit ROOM;

void create()
{
        set("short", "黑风堂");
        set("long", @LONG
这里就是山寨集会的大厅。中间并排放着两把龙虎狡
椅，两位寨主分别坐在上面。两边站着两排山贼。四周墙
上挂着几幅名画，一看就知道是珍品。
LONG
        );
        set("exits", ([ 
            "south"   : __DIR__"corr03",
]));
        setup();
        replace_program(ROOM);
}

