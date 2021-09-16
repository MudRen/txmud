// /d/wudu/zhaoze.c

inherit ROOM;

void create()
{
        set("short", "егдѓ");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "east"      : __DIR__"zhaoze01",
            "southwest" : __DIR__"path8",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

