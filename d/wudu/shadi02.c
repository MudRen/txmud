// /d/wudu/shadi02.c

inherit ROOM;

void create()
{
        set("short", "ɳ��");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northwest" : __DIR__"shadi",
            "south"     : __DIR__"tree8",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

