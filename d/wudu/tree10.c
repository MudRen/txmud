// /d/wudu/tree10.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "north"     : __DIR__"tree7",
            "east"      : __DIR__"tree9",
            "southwest" : __DIR__"bshan",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

