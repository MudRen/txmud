// /d/wudu/tree.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "southwest" : __DIR__"tree2",
            "southeast" : __DIR__"tree1",
            "west"      : __DIR__"road1",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

