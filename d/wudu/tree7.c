// /d/wudu/tree7.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "north" : __DIR__"shadi01",
            "south" : __DIR__"tree10",
            "east"  : __DIR__"tree8",
            "west"  : __DIR__"shanya",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

