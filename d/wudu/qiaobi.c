// /d/wudu/qiaobi.c

inherit ROOM;

void create()
{
        set("short", "ÇÍ±Ú");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northwest" : __DIR__"xiaoxi",

]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

