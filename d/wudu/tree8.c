// /d/wudu/tree8.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "north" : __DIR__"shadi02",
            "south" : __DIR__"tree9",
            "west"  : __DIR__"tree7",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

