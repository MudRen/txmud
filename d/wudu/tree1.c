// /d/wudu/tree1.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northwest" : __DIR__"tree",
            "southeast" : __DIR__"tree3",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

