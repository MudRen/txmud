// /d/wudu/tree2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "north"     : __DIR__"tree1",
            "northwest" : __DIR__"road1",
            "southwest" : __DIR__"road2",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

