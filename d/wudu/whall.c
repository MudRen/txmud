// /d/wudu/whall.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"store",
            "east"   : __DIR__"hall",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

