// /d/wudu/shadi01.c

inherit ROOM;

void create()
{
        set("short", "ɳ��");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northeast" : __DIR__"shadi",
            "south"     : __DIR__"tree7",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

