// /d/wudu/tree3.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northwest" : __DIR__"tree1",
            "southeast" : __DIR__"xiaoxi",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

